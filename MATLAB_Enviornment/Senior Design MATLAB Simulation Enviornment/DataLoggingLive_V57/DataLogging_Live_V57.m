%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                        %
%	Live Matlab Plotting Via Serial      %
%	Serial Port: COM*                    %
%                                        %
%	Data Rate 9600                       %
%	Delay 10ms = Sample Frequency 100Hz  %
%                                        %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
clear
clc

%User Defined Properties 
serialPort = 'COM7';                            % define COM port #
plotTitle = 'Motor Torque Output (Float)';      % plot title
xLabel = 'Elapsed Time (s)';                    % x-axis label
yLabel = 'Torque Output 1 (A)';                                % y-axis label
plotGrid = 'on';                                % 'off' to turn off grid
min = 0;                                        % set y-min
max = 25;                                       % set y-max
scrollWidth = 20;                               % display period in plot, plot entire data log if <= 0
delay = 0.01;                                   % make sure sample faster than resolution

%Define Function Variables
time = 0;
data = 0;
count = 0;
 
%Set up Plot
plotGraph = plot(time,data,'-mo','LineWidth',1,'MarkerEdgeColor','k','MarkerFaceColor',[.49 1 .63],'MarkerSize',2);

%Set plot title, and axis lables
title(plotTitle,'FontSize',25);
xlabel(xLabel,'FontSize',15);
ylabel(yLabel,'FontSize',15);
axis([0 10 min max]);
grid(plotGrid);
 
%Open Serial COM Port
s = serial(serialPort);
s.InputBufferSize = 12;
set(s,'Terminator','LF');
set(s,'BaudRate', 38400);
set(s,'DataBits', 8);
set(s,'Parity','none');
set(s,'StopBits', 2);
set(s,'FlowControl','none');
set(s,'InputBufferSize', 12);
set(s,'BytesAvailableFcnCount', 12);
set(s,'BytesAvailableFcnMode','byte');

disp('Close Plot to End Session');
pause(delay);
fopen(s);
pause(1);

%Create and open text log file
fileID = fopen('DataLog_Torque1_Torque2_Angle.txt','w');
fprintf(fileID,'%s,%s,%s,%s\n','Time(s)','Torque1(A)','Torque2(A)','Steering_Angle(Degrees)');

tic
 
while ishandle(plotGraph) %Loop when Plot is Active
    Rx_data_packet = fread(s, 3, 'float32') %Read torque_data from Serial as Float      
        if(~isempty(Rx_data_packet) && isfloat(Rx_data_packet)) %Make sure torque_data Type is Correct       
           
            %Plot some given data
            count = count + 1;    
            time(count) = toc;                                              %Extract Elapsed Time
            data(count) = Rx_data_packet(1);                                %Extract 1st torque_data Element

            %Set Axis according to Scroll Width
            if(scrollWidth > 0)
                set(plotGraph,'XData',time(time > time(count)-scrollWidth),'YData',data(time > time(count)-scrollWidth));
                axis([time(count)-scrollWidth time(count) min max]);                
                else
                set(plotGraph,'XData',time,'YData',data);
                axis([0 time(count) min max]);
            end
            
            %Rx_data_packet(3) is the current steering wheel angle in
            %binary, 0 thru 180 degrees maps to 0 thru 2048;
            %181 thru 360 degrees maps to 2049 thru 4096;
            
            A = [toc, Rx_data_packet(1), Rx_data_packet(2), Rx_data_packet(3)];     %Create 4x1 array of current timestamp and both read torque values
            fprintf(fileID,'%6.6f,%8.8f,%8.8f,%f\r\n',A);              %Save current into the log file

           %Allow MATLAB to Update Plot
           pause(delay);
           %Rx_data_packet = 0;
           
        end
end

%Close Serial COM Port and Delete useless Variables
fclose(s);
%Close log file
fclose(fileID);
clear count Rx_data_packet delay max min plotGraph plotGrid plotTitle ...
       scrollWidth serialPort xLabel yLabel A ans data fileID s time;

disp('Session Terminated...');