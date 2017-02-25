 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                        %
%                                        %
%	Live Matlab Plotting Via Serial      %
%	Serial Port: COM*                    %
%	Data Rate 9600                       %
%	Delay 10ms = Sample Frequency 100Hz  %
%                                        %
%                                        %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clear
clc

%User Defined Properties 
serialPort = 'COM7';            % define COM port #
%plotTitle = 'Motor Torque Outputs';  % plot title
%xLabel = 'Elapsed Time (s)';    % x-axis label
%yLabel = 'Data';                % y-axis label
%plotGrid = 'on';                % 'off' to turn off grid
%min = 0;                     % set y-min
%max = 500;                      % set y-max
%scrollWidth = 20;               % display period in plot, plot entire data log if <= 0
%delay = 0.5;                    % make sure sample faster than resolution
%dat = [];

%Define Function Variables
%time = 0;
%data = 0;
%count = 0;
 
%Set up Plot
%plotGraph = plot(time,data,'-mo','LineWidth',1,'MarkerEdgeColor','k','MarkerFaceColor',[.49 1 .63],'MarkerSize',2);

%Set plot title, and axis lables
%title(plotTitle,'FontSize',25);
%xlabel(xLabel,'FontSize',15);
%ylabel(yLabel,'FontSize',15);
%axis([0 10 min max]);
%grid(plotGrid);
 
%Open Serial COM Port
s = serial(serialPort);
s.InputBufferSize = 6;
set(s,'Terminator','LF');
set(s,'BaudRate', 38400);
set(s,'DataBits', 8);
set(s,'Parity','none');
set(s,'StopBits', 2);
set(s,'FlowControl','none');
set(s,'InputBufferSize', 6);

%set(s,'BytesAvailableFcn', 'dat = fread(s,6,''uint8'');');
set(s,'BytesAvailableFcnCount', 6);
set(s,'BytesAvailableFcnMode','byte'); 
fopen(s);

%disp('Close Plot to End Session');
pause(1);
%Configure text log file
%x = 0:.1:1;
%A = [x; exp(x)];

%Create and open text log file
fileID = fopen('samplelog3.txt','w');
fprintf(fileID,'%s,%s,%s,%s,%s\n','Time','Value1','Value2','Value3','Value4');
pause(1);

tic
i = 1; 
while(i<100) %Loop when Plot is Active
    dat = fread(s,6,'uint8');
    
    if(~isempty(dat)) %Make sure Data Type is Correct        
        %count = count + 1;    
        %time(count) = toc;    %Extract Elapsed Time    
            TD1H = dat(2)
            TD1L = dat(3)
            TI1H = dat(4)
            TI1L = dat(5)          
      
            %TD1Cat = TD1H*256 + TD1L;
            %TI1Cat = TI1H*256 + TI1L;
            %TI1Cat = double(TI1Cat);
            %TI1Cat = (TI1Cat/1000);
            
            %Torque1 = (TD1Cat+TI1Cat);
            
            %fprintf('%f\r\n',Torque1)           
            %fprintf('%f\r\n',Torque1)        
            %Create 2x1 array of current timestamp and read value
         
            t = toc;
            fprintf(fileID,'%5.5f,%f,%f,%f,%f\n',t,TD1H,TD1L,TI1H,TI1L);   %Save current into the log file
            i = i+1;        
%        %Set Axis according to Scroll Width
%        if(scrollWidth > 0)
%        set(plotGraph,'XData',time(time > time(count)-scrollWidth),'YData',data(time > time(count)-scrollWidth));
%        axis([time(count)-scrollWidth time(count) min max]);
%        else
%        set(plotGraph,'XData',time,'YData',data);
%        axis([0 time(count) min max]);
%        end
         
        %Allow MATLAB to Update Plot
%       pause(delay);
%       dat = 0;
        pause(0.001);
    end
end

%Close Serial COM Port and Delete useless Variables
fclose(s);
%Close log file
fclose(fileID);
clear count dat delay max min plotGraph plotGrid plotTitle ...
%       scrollWidth serialPort xLabel yLabel;

disp('Session Terminated...');