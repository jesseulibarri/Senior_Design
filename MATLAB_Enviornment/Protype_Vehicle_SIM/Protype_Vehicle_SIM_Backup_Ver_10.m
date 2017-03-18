%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   Motor/Wheel Parameters
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
B = 0.5;        %Magnetic Flux Density (T)
Cemf = 3;       %Back EMF constant
Vemf = 0;
Im = 0;         %Current supplied to the motor (A)
Vbatt = 48;     %Voltage supplied to the motor (V)   
G = 5;         %Gear ratio from motor to wheel (Nw/Nm)
r = 0.1016;     %Radius of main motor rotor (m)
R = 0.2286;     %Radius of wheel (m)
Rper = 2*3.14*R;
Jl = 0.000444;  %Moment of Inertia of load (wheel)
Jm = 0.02194;   %Moment of Inertia of motor
L = 0.0508;     %Length of motor winding (m)
Pmax = 500;     %Maximum power rating of motor (W)
Imax = (Pmax/Vbatt);

Mm = 4.26;      %Mass of motor (Kg)
Mw = 1.7;       %Mass of wheel (Kg)
f = 0;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   Vehicle/Enviornment Parameters
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
g = -9.81;      %Gravitational acceleration (m/s2)
m = 81;         %Vehicle mass (kg)
A = 3.56;       %Effective frontal vehicle cross-sectional area (m2)
h = 0.1524;     %Height of vehicle CG above the ground (m)
a = 0.6;        %Distance of front and rear axles, respectively, from the vertical projection point of vehicle CG onto the axle-ground plane (m)
b = 0.6;        %Distance of front and rear axles, respectively, from the vertical projection point of vehicle CG onto the axle-ground plane (m)
Cd = 0.076;     %Aerodynamic drag coefficient (N·s2/kg·m)
p = 1.2;        %Mass density of air (kg/m3)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   Active Forces on System
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Ax = 0;         %Longitudinal vehicle acceleration (m/s^2)
Vxi = 0;       %Initial Longitudinal vehicle velocity (m/s)
Vxf = 0;        %Final Longitudinal vehicle velocity (m/s)
Vxd = 0;        %Change in velocity (m/s)
Vxfmph = 0;     %Velocity in mph
Fxf = 0;        %Longitudinal forces on the vehicle at the front and rear wheel ground contact points, respectively (N)
Fxr = 0;        %Longitudinal forces on the vehicle at the front and rear wheel ground contact points, respectively (N)
beta = 0;       %Incline angle (rad)
dt = 0.1;         %Change in time between calculations (s)

Fzf = 0.5*m*g*cos(beta);       %Vertical load forces on the vehicle at the front and rear ground contact points, respectively (N)
Fzr = 0.5*m*g*cos(beta);       %Vertical load forces on the vehicle at the front and rear ground contact points, respectively (N)
Kincf = 0.015;               %Kinetic coefficient of rolling bike tires
Statf = 1;

Fxf = 0; %Force exerted on the front wheel (0 since there is no motor)

%Zero vertical acceleration and zero pitch torque require
%Fzf = (+h(Fd-mgsin(beta)-m*Vx)+b*mgcos(beta))/(a+b);
%Fzr = (-h(Fd-mgsin(beta)-m*Vx)+b*mgcos(beta))/(a+b);
%Note that Fzf + Fzr = mg·cos?
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


try
    %Select the total number of floats, (num_of_in_float), 
    %being sent via serial every cycle; and which speed 
    %you would like to sample for input.
    serialPort = 'COM4';                %Define COM port #
    baudrate = 76800;                   %Define baudrate of data
    num_of_in_float = 1;                %Define # of Float/packet
    delay = 0.01;                      %Make sure sample faster than resolution

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
    set(s,'Terminator','LF');
    set(s,'BaudRate', baudrate);
    set(s,'DataBits', 8);
    set(s,'Parity','none');
    set(s,'StopBits', 1);
    set(s,'FlowControl','none');
    set(s,'InputBufferSize', num_of_bytes);
    set(s,'OutputBufferSize', 10);
    set(s,'BytesAvailableFcnCount', num_of_bytes);
    set(s,'BytesAvailableFcnMode','byte');

    %Open the Serial Com Port and allow to open (pause)
    fopen(s);
    pause(1);

    %Set the internal timer at the execution of the 'tic' command. 
    %This timer's value can be accessed as by a subsequent call to 'toc'. 
    tic

    %Loop when Plot is Active 
    while ishandle(plotGraph)

        Rx_data_packet = fread(s, num_of_in_float, 'float32');        
        %Read data off the serial bus as 32-bit floats.      

            if(~isempty(Rx_data_packet) && isfloat(Rx_data_packet))  
            %Make sure read data is a Float and not an empty array      
           
                %Plot some given data
                count = count + 1;    
                time(count) = toc;                                   
                %Extract Elapsed Time
                if(count > 2)
                    dt = (time(count)-time(count-1));
                end
                
%                 %Calculate back EMF at the current linear speed, current 
%                 %voltage available, then lastly, the maximum current the 
%                 %motor can accept at the given speed.
%                 emf = (Vxi*Vemf)
%                 if(emf > Vm_i)
%                     Vm_f = 0.001;
%                 else
%                     Vm_f = Vm_i - emf;
%                 end
%                 %Recieve the Torque (currrent) command from controller
%                 Im = Rx_data_packet(1)
%                 
%                 %Check if current power is less than the available motor
%                 %power, if not set current to maximum available. 
%                 Pcurr = Imax_i*Vm_f;
%                 Pdiff = Pmax - Pcurr;
%                 Imax_f = Imax_i*(Pdiff)
%                 if(Pdiff < 0)
%                     Imax_f = 0;
%                 end
%                 if(Pcurr > Pmax)
%                     fprintf('Motor Max Power Reached')
%                     Im = Imax_f
%                 end
%                 
                %Calculate back EMF at the current linear speed, current 
                %voltage available, then lastly, the maximum current the 
                %motor can accept at the given speed.
                Vemf = (Vxi*Cemf)
                %Recieve the Torque (currrent) command from controller
                Imset = Rx_data_packet(1)
                
                if(Vemf < Vbatt)
                    Vcurr = Vbatt - Vemf                  
                    Pcurr = Vcurr*Im

                    if(Pmax-Pcurr > 0)
                        Imax = (Pmax-Pcurr)/Vbatt
                        if(Imset < Imax)
                            Im = Imset
                        end
                    else
                        fprintf('Motor Maximum Power Reached')
                        Im = Imax;
                    end
                    %Check if current power is less than the available motor
                    %power, if not set current to maximum available. 
                else
                    Im = 0
                    fprintf('Motor Maximum Speed Reached')
                end
                if(Imset > Imax)
                   Im = Imax
                else
                   Im = Imset
                end
                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                %   Linear Motion Calculations:
                %
                %   The vehicle motion is determined by the net effect of all the forces and torques acting on it. 
                %   The longitudinal tire forces push the vehicle forward or backward. The weight mg of the vehicle 
                %   acts through its center of gravity (CG). Depending on the incline angle, the weight pulls the 
                %   vehicle to the ground and either pulls it backward or forward. Whether the vehicle travels forward or backward, 
                %   aerodynamic drag slows it down. For simplicity, the drag is assumed to act through the CG.
                %
                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%               
                 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                N = abs(Fzr + Fzf)            %Normal force of vehicle
                Fu = -(N*urub)              %Force of kenetic friction on vehicle in motion                              
                Fxr = m*((2*B*Im*L*r)/(((Jl/R)*G)+((Jm/R)*(1/G))))%Force exerted from the motor on the rear wheel

                Fd = -0.5*(Cd*p*A*(Vxi^2)) %Aerodynamic drag force (N) acting in oposition to the direction of motion                  
                Fx_m = (Fxf + Fxr) %Net Force propelling the vehicle forward, sum of the forces applied by each wheel
                Fnet = ((Fx_m + Fd) - (m*g*sin(beta)));
                Ax = Fnet/m; %Current acceleration of vehicle, Net force acting on the vehicle divided by the mass of the vehicle

                Vxd = dt*Ax    %Acceleration times change in time equals the change in velocity
                if(Vxi + Vxd > 0)
                    Vxf = Vxi + Vxd %Initial velocity plus the change in velocity equals final velocity
                else
                    Vxf = 0
                end
                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                
                Vxfmph = 2.23694*(Vxf)
                %Send = uint8(Vxfmph)
                Send = num2str(Vxfmph,'%.1f')
                %Send = num2str(Vxfmph)
                %fwrite(s, Send)
                fprintf(s,'%s',Send)
                fprintf(s, 'G')
                %pause(delay);
                
                %Extract user selected data to graph
                data(count) = Vxfmph;
                Vxi = Vxf;
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
            
            if(Logging == 1)
                %Save all input floats to the log file,
                %first with the current time, followed
                %by all of the read floats, ending with
                %a new-line. Log is CSV compatable.
                fprintf(fileID,'%f,',toc);
                for i = 1:num_of_in_float
                    fprintf(fileID,'%f,',Rx_data_packet(i));  
                end
                fprintf(fileID,'%f,',Im);
                fprintf(fileID,'%f,',Vxfmph);                        
                fprintf(fileID,'\r\n');
            end
            
            %Allow MATLAB time to Update Plot
            pause(delay);

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