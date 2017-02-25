%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                        %
%                                        %
%	Live Matlab Plotting Via Serial      %
%	Serial Port: COM*                    %
%	BaudRate = 38400                     %
%	Delay 10ms = Sample Frequency 100Hz  %
%                                        %
%                                        %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clear
clc

%User Defined Properties 
serialPort = 'COM7';       % define COM port #

%Define Function Variables
time = 0;
data = 0;

%Turn graphing feature on (1) or off (0)
Graph = 1;
 
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

set(s,'BytesAvailableFcnCount', 6);
set(s,'BytesAvailableFcnMode','byte'); 
fopen(s);

%Create and open text log file
fileID = fopen('samplelog3.txt','w');
fprintf(fileID,'%s,%s,%s,%s,%s\n','Time','Value1','Value2','Value3','Value4');
pause(1);

tic
i = 0; 

while(i<100) %Loop for number of samples
    
    dat = fread(s,6,'uint8');
        if(~isempty(dat)) %Make sure Data is not empty         
            TD1H = dat(2);
            TD1L = dat(3);
            C = union(A,B)
            
            TI1H = dat(4);
            TI1L = dat(5);
            C = union(A,B)
                      
            t = toc; %Extract Elapsed Time 
            fprintf(fileID,'%i,%i,%i,%i,%i\n',t,TD1H,TD1L,TI1H,TI1L);   %Save current into the log file
            i = i+1;
    end
end
fclose(s);

if(Graph == 1)
    filename = 'samplelog3.txt';
    [A,delimiterOut]=importdata(filename);
    RawUARTData = A.data;

    i=1;
    RRaw = zeros(1,5);
    X = zeros(1,100);
    Y = zeros(1,100);
    Length = length(RawUARTData);

    for i=1:Length
        
        RRaw = RawUARTData(i,:);
        Time = RRaw(1)
        X(i) = Time;
        TD1H = RRaw(2);
        TD1L = RRaw(3);
        TI1H = RRaw(4);
        TI1L = RRaw(5);
        TD1Cat = TD1H*256 + TD1L;
        TI1Cat = TI1H*256 + TI1L;
        TI1Cat = double(TI1Cat);
        TI1Cat = (TI1Cat/1000);
        Torque1 = (TD1Cat+TI1Cat)
        Y(i) = Torque1;
        
    end 
    
    %Plot collected data points
    plotTitle = 'Motor Torque Output (UART)';       % plot title
    xLabel = 'Elapsed Time (s)';                    % x-axis label
    yLabel = 'Torque 1';                            % y-axis label
    plotGrid = 'on';                                % 'off' to turn off grid
    stem(X,Y,':diamondr')

    %Set plot title, and axis lables
    title(plotTitle,'FontSize',25);
    xlabel(xLabel,'FontSize',15);
    ylabel(yLabel,'FontSize',15);
    axis([0 max(Time) min(Y) 2*max(Y)]);
    grid(plotGrid);    

    fclose(fileID);
    
end

clc
clear count dat delay max min plotGraph plotGrid plotTitle ...
       scrollWidth serialPort xLabel yLabel;

disp('Session Terminated...');