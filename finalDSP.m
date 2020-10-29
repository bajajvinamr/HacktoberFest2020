%RESPONSE SPECTRUM % 
clear global; 
clc;

%IMPORT EL CENTRO DATA 
[elcentro] = xlsread('ELC.xls.xlsx');
t = elcentro(:,1);
E = elcentro(:,2);

%INPUT DATA 
xi = 0.02;
m = 1;
dt =t(2)-t(1);
T = (0.01:0.01:3)';
omega_n = 2*pi./T;
K = m.*omega_n.*omega_n;

%SOLUTION

D =zeros(length(T),1);
for j = 1: length(T)
wn = omega_n(j); 
k = K(j);
[u, v] = interpolation(xi,m,k,E,dt,wn);
D(j) = max(abs(u));
end

V = omega_n.*D;
A = omega_n.*omega_n.*D./386.09;

%FOURIER RESPONSE
n = length(E); 
Ts = t(2)-t(1);            % Sample Time
Fs = 1/Ts;                       % Sampling Frequency
NFFT = 2^nextpow2(n);            % Next power of 2 from length of data
Y = fft(E,NFFT)/n;
f = Fs/2*linspace(0,1,NFFT/2+1);
Iv = 1:length(f);                   % Index Vector

% POWER SPECTRAL DENSITY
Pxx = abs(fft(E,NFFT)).^2/length(E)/Fs;
Hpsd = dspdata.psd(Pxx(1:length(Pxx)/2),'Fs',Fs); 
Hpsd1 = dspdata.psd(Pxx,'Fs',Fs,'SpectrumType','twosided');

%PLOT RESPONSE 

figure(1);
plot(t,E)
title('EL Centro Spectrum', 'Fontsize',16);
xlabel('Time(sec)')
ylabel('Amplitude (g)')

figure(2);
plot(f,abs(Y(Iv))) 
title('Fourier Transform','Fontsize',14);
xlabel('Frequency (Hz)')
ylabel('Amplitude (m)')

figure(3);
plot(Hpsd)

figure(4);
plot(Hpsd1)

figure(5);
subplot(3,1,1);
plot(T,D, 'r', 'Linewidth',2);
title('Deformation Response Spectrum', 'Fontsize', 16);
ylabel('D, in.', 'Fontsize',16, 'Fontweight', 'Bold');
subplot(3,1,2); 
plot(T,V, 'r','Linewidth',2);
title('Pseudo-Velocity Response Spectrum','Fontsize',16); 
ylabel('V, in./sec', 'Fontsize',16, 'Fontweight', 'Bold');
subplot(3,1,3);
plot(T,A,'r','Linewidth', 2);
title('Pseudo-Acceleration Response Spectrum', 'Fontsize',16);
ylabel('A, g', 'Fontsize', 16, 'Fontweight', 'Bold');
xlabel('T_n, sec', 'Fontsize', 16, 'Fontweight', 'Bold');

figure(6);
plot(T,D, 'r', 'Linewidth',2);
title('Deformation Response Spectrum', 'Fontsize', 16);
ylabel('D, in.', 'Fontsize',16, 'Fontweight', 'Bold');
xlabel('T_n, sec', 'Fontsize', 16, 'Fontweight', 'Bold');

figure(7);
plot(T,V, 'r','Linewidth',2);
title('Pseudo-Velocity Response Spectrum','Fontsize',16); 
ylabel('V, in./sec', 'Fontsize',16, 'Fontweight', 'Bold');
xlabel('T_n, sec', 'Fontsize', 16, 'Fontweight', 'Bold');

figure(8);
plot(T,A,'r','Linewidth', 2);
title('Pseudo-Acceleration Response Spectrum', 'Fontsize',16);
ylabel('A, g', 'Fontsize', 16, 'Fontweight', 'Bold');
xlabel('T_n, sec', 'Fontsize', 16, 'Fontweight', 'Bold');


