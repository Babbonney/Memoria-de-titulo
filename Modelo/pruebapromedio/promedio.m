%pwm promedio
clc;
clearvars;
d_motores = readtable('outputspromedio.csv');
tiempo= d_motores.timestamp(50+1:end-30)/1000000;
m1 = d_motores.output_0_ (50+1:end-30);
m2  = d_motores.output_1_ (50+1:end-30);
m3 = d_motores.output_2_ (50+1:end-30);
m4 = d_motores.output_3_ (50+1:end-30);

prom_m1 = mean(m1);
prom_m2 = mean(m2);
prom_m3 = mean(m3 );
prom_m4 = mean(m4 );
prom_m1_norm = (prom_m1 - 1100)/900;
prom_m2_norm = (prom_m2 - 1100)/900;
prom_m3_norm = (prom_m3 - 1100)/900;
prom_m4_norm = (prom_m4 - 1100)/900;
fprintf('Promedios de motores pwm:\n');
fprintf('M1: %.4f\n', prom_m1);
fprintf('M2: %.4f\n', prom_m2);
fprintf('M3: %.4f\n', prom_m3);
fprintf('M4: %.4f\n', prom_m4);
fprintf('Promedios de motores normalizado:\n');
fprintf('M1: %.4f\n', prom_m1_norm);
fprintf('M2: %.4f\n', prom_m2_norm);
fprintf('M3: %.4f\n', prom_m3_norm);
fprintf('M4: %.4f\n', prom_m4_norm);
