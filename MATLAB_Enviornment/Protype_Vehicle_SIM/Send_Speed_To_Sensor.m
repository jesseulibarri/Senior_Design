try
    %Select the total number of floats, (num_of_in_float), 
    %being sent via serial every cycle; and which speed 
    %you would like to sample for input.
    serialPort = 'COM4';                %Define COM port #
    baudrate = 76800;                   %Define baudrate of data
    num_of_in_float = 1;                %Define # of Float/packet
    delay = 0.8;                      %Make sure sample faster than resolution

    %Log file name and column titles 
    Logging = 0; %Set this to turn the data log on/off
    Log_Title = 'Vehicle_SIM_Log.txt';
    fileID = fopen(Log_Title,'w');
    fprintf(fileID,'%s,%s,%s,%s,%s,%s,%s\r\n','Time(s)','Input Current','Velocity of Vehicle (mph)','???');
    
    %Other User Defined Properties
    plotTitle = 'Vehicle Speed vs Time';   %Plot title
    xLabel = 'Elapsed Time(s)';         %X-axis label
    yLabel = 'Current Vehicle Velocity (mph)';        %Y-axis label
    plotGrid = 'on';                    %'off' to turn off grid
    scrollWidth = 20;                   %Display period in plot, plot entire data log if <= 0

    %Choose which input float to graph (float_to_graph,then
    %indicate the maximum and minimum value that it can be.
    float_to_graph = 1;                 %Define which float to graph     
    min = 0;                            %Define y-min
    max = 100;                           %Define y-max

    %Define Function Variables
    time = 0;
    data = 0;
    count = 0;
    num_of_bytes = (num_of_in_float*4);

    %Set up Plot
    plotGraph = plot(time,data,'-mo','LineWidth',1,'MarkerEdgeColor','k','MarkerFaceColor',[.49 1 .63],'MarkerSize',2);

    %Set plot grid, title, and axis lables
    title(plotTitle,'FontSize',25);
    xlabel(xLabel,'FontSize',15);
    ylabel(yLabel,'FontSize',15);
    axis([0 10 min max]);

    %Append grid to plot at users command
    grid(plotGrid);

    %Generate plot and pause slightly to let it open
    disp('Close Plot to End Session');
    pause(delay);

    %Create and Configure Serial COM Port with user settings
    s = serial(serialPort);
    s.InputBufferSize = num_of_bytes;
    set(s,'Terminator','G');
    set(s,'BaudRate', baudrate);
    set(s,'DataBits', 8);
    set(s,'Parity','none');
    set(s,'StopBits', 1);
    set(s,'FlowControl','none');
    set(s,'InputBufferSize', num_of_bytes);
    set(s,'OutputBufferSize', 5);
    set(s,'BytesAvailableFcnCount', num_of_bytes);
    set(s,'BytesAvailableFcnMode','byte');

    %Open the Serial Com Port and allow to open (pause)
    fopen(s);
    pause(1);
    
    
    String = 1;
    GCASE = 0;

    tic
    
while ishandle(plotGraph) 
                    
        Vxfmph = 12.345;

        if(String == 1)
            SendString = num2str(Vxfmph,'%.1f')
            SendString;
            fprintf(s,'%s',SendString);
        end
        if(String == 0)
            SendUChar = num2str(Vxfmph,'%.1f')
            SendUChar;
            fwrite(s,SendUChar,'char')
            %pause(delay)
        end
        if(GCASE == 1)
            fprintf(s, 'G')
            fprintf(s, 'G')
            fprintf(s, 'G')
            fprintf(s, 'G')
        end
        fwrite(s, 'G', 'char')
        pause(delay);
      
        %Plot some given data
        count = count + 1;    
        time(count) = toc;                                   
        %Extract Elapsed Time
        data(count) = Vxfmph;
        %Plot some given data               
        %Adjust the graph's X-axis according to 'Scroll Width'.
        %It is adjusted using the current 'time' and 'count'. 
        if(scrollWidth > 0)
            set(plotGraph,'XData',time(time > time(count)-scrollWidth),'YData',data(time > time(count)-scrollWidth));
            axis([time(count)-scrollWidth time(count) min max]);                
        %Plot the given float without adjusting for 'Scroll Width'
        else
            set(plotGraph,'XData',time,'YData',data);
            axis([0 time(count) min max]);
        end
       
        
        
        
end

catch ME
   fprintf(1, 'An error occured, please ensure all user defined variables are set correctly\r\n'); 
   fprintf(1, 'ERROR MESSAGE:\n%s\n\n', ME.message); 
end    

%Close Serial COM Port and Delete useless Variables
fclose(s);
%Close log file
fclose(fileID);
%Clear out all of the used variables and terminate the script.
clear count Rx_data_packet delay max min plotGraph plotGrid plotTitle ...
       scrollWidth serialPort xLabel yLabel A ans data fileID s time;
  
disp('Log/Graph Script Terminated...');
disp('Thank you for choosing EriLog for your scripting needs!');