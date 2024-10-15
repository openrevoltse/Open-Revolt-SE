clear all
clc
close
% Create an serial port object where you specify the USB port (look in
% Arduino->tools -> port) and the baud rate (9600)
s = serial('COM3','BaudRate',1000);

try
    fopen(s);
catch err
    fclose(instrfind);
    error('Make sure you select the correct COM Port where the Arduino is connected.');
end
Tmax = 600; % Total time for data collection (s)
Ts = 0.01; % Sampling time (s)
i = 1;
data = [0,0];
t = 0;
tic % Start timer






while toc <= Tmax
    i = i + 1;
   
    rawData = fscanf(s,'%f %f\n');
    data(i,1) = rawData(1);
    data(i,2) = rawData(2);
    Corrente=data(1:end,1);
    Setpoint=data(1:end,2);
 % If matlab read the data faster than the sampling rate set in arduino, force sampling to be the same as the
    % sampling time set in matpab code, If matlab is reading slower,
    % nothing can be done.

       drawnow
    t(i) = toc;
        
        axis([0 50 0 5]);
        plotGraph = plot(t,Corrente,'-r')  % every AnalogRead needs to be on its own Plotgraph
        hold on                            %hold on makes sure all of the channels are plotted
        plotGraph1 = plot(t,Setpoint,'-b')
       
    if i > 1
        T = toc - t(i-1);
        while T < Ts
            T = toc - t(i-1);
        end
    end
    t(i) = toc;
end

tempo=[0:T:T*i-T];
tempo=[tempo(50:end)];
I=[Corrente(50:end)];
Set=[Setpoint(50:end)];

figure(2)
plot(tempo,I)
hold on
grid on
plot(tempo,Set)

fclose(s);