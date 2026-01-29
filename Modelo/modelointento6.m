clearvars; close all; clc;

%% 1. CARGA DE DATOS
tiempomotores = readtable('datosmotores.xlsx');
tiempovelocidades = readtable('datosvel.xlsx');
d_motores = readtable('prueba_actuator_outputs_0.csv');
d_vel = readtable('prueba_vehicle_angular_velocity_0.csv');

%% 2. PROCESAMIENTO DE MOTORES
m1 = (d_motores.output_0_ - 1100) ./ 800 - 0.35;
m2 = (d_motores.output_1_ - 1100) ./ 800 - 0.35;
m3 = (d_motores.output_2_ - 1100) ./ 800 - 0.35;
m4 = (d_motores.output_3_ - 1100) ./ 800 - 0.35;

% Mezcla de comandos (Mixer inverso)
u1_raw = -m1 + m2 + m3 - m4; % Roll
u2_raw =  m1 - m2 + m3 - m4; % Pitch
u3_raw =  m1 + m2 - m3 - m4; % Yaw

%% 3. SINCRONIZACIÓN
t_vel_orig = tiempovelocidades.tsNormalizado - tiempovelocidades.tsNormalizado(1);
t_mot_orig = tiempomotores.Tsnormalizado - tiempomotores.Tsnormalizado(1);
t_ref = t_vel_orig; 

u1 = interp1(t_mot_orig, u1_raw, t_ref, 'previous', 'extrap');
u2 = interp1(t_mot_orig, u2_raw, t_ref, 'previous', 'extrap');
u3 = interp1(t_mot_orig, u3_raw, t_ref, 'previous', 'extrap');

u1 = [u1(2:end); u1(end)];
u2 = [u2(2:end); u2(end)];
u3 = [u3(2:end); u3(end)];
y_raw = [d_vel.xyz_0_, d_vel.xyz_1_, d_vel.xyz_2_];

%% 4. PRE-PROCESAMIENTO GLOBAL
idx = ~isnan(y_raw(:,1)) & ~isnan(u1);
span = 12; 
y_filt = movmean(y_raw(idx,:), span);
u_filt = movmean([u1(idx), u2(idx), u3(idx)], span);
t_ref = t_ref(idx);
y_clean = detrend(y_filt);
u_clean = detrend(u_filt);
Ts = mean(diff(t_ref));

%% 5. BÚSQUEDA ITERATIVA CON PUNTUACIÓN EQUILIBRADA (ORDEN 3)
mejor_puntuacion = -inf;
mejor_modelo = [];
mejor_recorte = [0, 0];
mejores_fits_individuales = [0, 0, 0];

paso = 100; 
rango_inicio = 100:paso:2500; 
rango_final = 100:paso:500;  

total_iteraciones = length(rango_inicio) * length(rango_final);
iteracion = 0;

fprintf('Iniciando búsqueda iterativa (Criterio: Equilibrio R-P)...\n');
fprintf('Total combinaciones: %d\n', total_iteraciones);
fprintf('--------------------------------------------------\n');

for r1 = rango_inicio
    for r2 = rango_final
        iteracion = iteracion + 1;
        
        if mod(iteracion, 50) == 0
            fprintf('Progreso: %.1f%% (Iter %d/%d)\n', (iteracion/total_iteraciones)*100, iteracion, total_iteraciones);
        end
        
        if (r1 + r2) >= size(y_clean, 1) * 0.6, continue; end
        
        y_iter = y_clean(r1+1 : end-r2, :);
        u_iter = u_clean(r1+1 : end-r2, :);
        
        split = floor(0.7 * size(y_iter, 1));
        d_tr = iddata(y_iter(1:split, :), u_iter(1:split, :), Ts);
        d_va = iddata(y_iter(split+1:end, :), u_iter(split+1:end, :), Ts);
        
        % Definición del modelo de Orden 3
        m_base = idss(zeros(3), zeros(3), eye(3), zeros(3), zeros(3), 'Ts', Ts);
        S = m_base.Structure;
        S.C.Free = false; S.D.Free = false; S.K.Free = false;
        m_base.Structure = S;
        
        opt = ssestOptions;
        opt.InitializeMethod = 'n4sid';
        opt.InitialState = 'estimate';
        opt.Focus = 'prediction';  
        opt.EnforceStability = false;
        opt.SearchMethod = 'lm';
        optc = compareOptions('InitialCondition','estimate');
        
        try
            m_curr = ssest(d_tr, m_base, opt);
            [~, fit_vals] = compare(d_va, m_curr, compareOptions('InitialCondition', 'estimate'));
            
            % --- LÓGICA DE SELECCIÓN EQUILIBRADA ---
            if all(fit_vals > 2) % Mínimo 2% en cada eje para considerar el modelo
                
                % Puntuación basada en el producto para castigar desequilibrios
                % (Damos un poco menos de peso al Yaw para no penalizar el R-P)
                puntuacion_actual = fit_vals(1) * fit_vals(2) * (max(fit_vals(3), 1)^0.5);
                
                % Diferencia máxima permitida entre Roll y Pitch (para evitar 5% vs 50%)
                dif_rp = abs(fit_vals(1) - fit_vals(2));
                
                if puntuacion_actual > mejor_puntuacion && dif_rp < 25
                    mejor_puntuacion = puntuacion_actual;
                    mejor_modelo = m_curr;
                    mejor_recorte = [r1, r2];
                    mejores_fits_individuales = fit_vals;
                    
                    fprintf('\n>>> NUEVO MEJOR EQUILIBRADO:\n');
                    fprintf('    Fits: [Roll: %.1f%%, Pitch: %.1f%%, Yaw: %.1f%%]\n', ...
                            fit_vals(1), fit_vals(2), fit_vals(3));
                    fprintf('    Dif R-P: %.1f%% | R1: %d, R2: %d\n', dif_rp, r1, r2);
                end
            end
        catch
            continue;
        end
    end
end

%% 6. RESULTADOS FINALES
if isempty(mejor_modelo)
    error('No se encontró un modelo equilibrado. Intenta reducir el paso o revisar los datos.');
else
    fprintf('\n--- Búsqueda Finalizada ---\n');
    fprintf('Configuración Óptima: R1=%d, R2=%d\n', mejor_recorte(1), mejor_recorte(2));
    fprintf('Fits Finales: Roll=%.2f%%, Pitch=%.2f%%, Yaw=%.2f%%\n', ...
            mejores_fits_individuales(1), mejores_fits_individuales(2), mejores_fits_individuales(3));
    
    % Validación Final
    y_f = y_clean(mejor_recorte(1)+1 : end-mejor_recorte(2), :);
    u_f = u_clean(mejor_recorte(1)+1 : end-mejor_recorte(2), :);
    sp = floor(0.7 * size(y_f, 1));
    d_va_f = iddata(y_f(sp+1:end, :), u_f(sp+1:end, :), Ts);
    
    figure('Name', 'Validación del Mejor Modelo Equilibrado', 'Color', 'w');
    compare(d_va_f, mejor_modelo);
    
    s_lo = mejor_modelo;
    disp('Matriz A del sistema:'); disp(s_lo.A);
    disp('Matriz B del sistema:'); disp(s_lo.B);
end