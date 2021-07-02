f = 1
amp = 5
DCbias=-3
Ts = 0.0001
t = -3:Ts:3-Ts;
signal = amp * sign(sin(2*pi*f*t));

plot(t, signal);
xlabel('Time')
ylabel('Amplitude')
title('Square wave of given signal')

m =0:20

a = rand(25,1)


fourier = a(1)