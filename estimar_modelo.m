clearvars
close all
clc

%% cargar datos
% Ocupar funcion readtable para leer desde excel
d_motores = readtable('datosmotores.xlsx')
d_vel = readtable('datosvelxlsx');


% Restar el valor de motor que elegiste y normalizar para este entre 0 y 1
% Pasar los motores a las acciones de control combinadas U

%% generaro variables de datos entrenamiento y validacion
% Ts = definir tiempo de muestreo;

% 70% entrenamiento, y 30% validacion
% data_entrlo = iddata(datos de salida (velocidades),datos de entrada (motores), Ts);
% data_vallo = iddata(datos de salida (velocidades),datos de entrada (motores), Ts);

%% estimar modelo
A_lo = zeros(3);
B_lo = zeros(3);
C_lo = eye(3);
D_lo = zeros(3);
K_lo = zeros(3);
Ts = definir tiempo de muestero;

m = idss(A_lo,B_lo,C_lo,D_lo,K_lo,'Ts',Ts);

S = m.Structure;
S.C.Free = false;
S.D.Free = false;
S.K.Free = false;  
%S.B.Free(1,2) = false; S.B.Free(2,2) = false; 
%S.B.Free(3,1) = false; %S.B.Free(4,1) = false;
m.Structure = S;

% configuracion del system identification
opt = ssestOptions;
opt.InitializeMethod = 'n4sid';
opt.InitialState = 'zero';
opt.Focus = 'simulation';  
opt.EnforceStability = true; opt.SearchMethod = 'gna';
optc = compareOptions('InitialCondition','zero');

mm = ssest(data_entrlo,m,opt);
s_lo = pem(data_entrlo,mm,opt);  % modelo longitudinal 

% compare: compara el modelo con los datos de validacion 
compare(data_vallo,s_lo,optc)

