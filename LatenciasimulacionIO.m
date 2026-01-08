clc
% Extraer los datos
elapsed = out.tiempo.data;

% Ignorar el primer sample
elapsed_valid = elapsed(2:end);

% Métricas básicas
tiempo_total_real = sum(elapsed_valid);
tiempo_promedio   = mean(elapsed_valid);

% Máximo y mínimo CON posición
[tiempo_max, idx_max_valid] = max(elapsed_valid);
[tiempo_min, idx_min_valid] = min(elapsed_valid);

% Corregir índice al vector original
idx_max = idx_max_valid + 1;
idx_min = idx_min_valid + 1;

% Jitter
jitter_std = std(elapsed_valid);

% Prints
fprintf('Tiempo real total: %.3f s\n', tiempo_total_real);
fprintf('Tiempo promedio por iteración: %.3f ms\n', tiempo_promedio*1000);

fprintf('Tiempo máximo: %.3f ms (posición %d)\n', tiempo_max*1000, idx_max);
fprintf('Tiempo mínimo: %.3f ms (posición %d)\n', tiempo_min*1000, idx_min);

fprintf('Jitter (desv. estándar): %.2f ms\n', jitter_std*1000);
