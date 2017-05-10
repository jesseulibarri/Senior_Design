%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   Motor/Wheel Parameters
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
B = 0.5;              %Magnetic Flux Density (T)
Cemf = 3;             %Back EMF constant
Vemf = 0;             %Back EMF Voltage from motor (V)
Vcurr = 0;
Im = 0;               %Current supplied to the motor (A)
Vbatt = 48;           %Voltage supplied to the motor (V)   
G = 5;                %Gear ratio from motor to wheel (Nw/Nm)
r = 0.1016;           %Radius of main motor rotor (m)
R = 0.2286;           %Radius of wheel (m)
Rper = 2*3.14*R;      %Perimeter of the wheel (m)
Jl = 0.000444;        %Moment of Inertia of load (wheel)
Jm = 0.02194;         %Moment of Inertia of motor
L = 0.0508;           %Length of motor winding (m)
Pmax = 500;           %Maximum power rating of motor (W)
Imax = (Pmax/Vbatt);  %Maximum current allowed by motor (A)
Imset = 0;            %Set current from controller (A)

Mm = 4.26;            %Mass of motor (Kg)
Mw = 1.7;             %Mass of wheel (Kg)
f = 0;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   Vehicle/Enviornment Parameters
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
g = -9.81;            %Gravitational acceleration (m/s2)
m = 81;               %Vehicle mass (kg)
A = 3.56;             %Effective frontal vehicle cross-sectional area (m2)
h = 0.1524;           %Height of vehicle CG above the ground (m)
a = 0.6;              %Distance of front and rear axles, respectively, from the vertical projection point of vehicle CG onto the axle-ground plane (m)
b = 0.6;              %Distance of front and rear axles, respectively, from the vertical projection point of vehicle CG onto the axle-ground plane (m)
Cd = 0.076;           %Aerodynamic drag coefficient (N·s2/kg·m)
p = 1.2;              %Mass density of air (kg/m3)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   Active Forces on System
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Ax = 0;               %Longitudinal vehicle acceleration (m/s^2)
Vxi = 0;              %Initial Longitudinal vehicle velocity (m/s)
Vxf = 0;              %Final Longitudinal vehicle velocity (m/s)
Vxd = 0;              %Change in velocity (m/s)
Vxfmph = 0;           %Velocity in mph
Fxf = 0;              %Longitudinal forces on the vehicle at the front and rear wheel ground contact points, respectively (N)
Fxr = 0;              %Longitudinal forces on the vehicle at the front and rear wheel ground contact points, respectively (N)
beta = 0;             %Incline angle (rad)
dt = 0.1;             %Change in time between calculations (s)
Pcurr = Vcurr*Im;
Fzf = 0.5*m*g*cos(beta);       %Vertical load forces on the vehicle at the front and rear ground contact points, respectively (N)
Fzr = 0.5*m*g*cos(beta);       %Vertical load forces on the vehicle at the front and rear ground contact points, respectively (N)
Kincf = 0.015;                 %Kinetic coefficient of rolling bike tires
Statf = 1;
Speed = 0;
Fxf = 0; %Force exerted on the front wheel (0 since there is no motor)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Zero vertical acceleration and zero pitch torque require
%Fzf = (+h(Fd-mgsin(beta)-m*Vx)+b*mgcos(beta))/(a+b);
%Fzr = (-h(Fd-mgsin(beta)-m*Vx)+b*mgcos(beta))/(a+b);
%Note that Fzf + Fzr = mg·cos?
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%Select the total number of floats, (num_of_in_float), 
%being sent via serial every cycle; and which speed 
%you would like to sample for input.
serialPort = 'COM7';                %Define COM port #
baudrate = 76800;                   %Define baudrate of data
num_of_in_float = 4;                %Define # of Float/packet
delay = 0.001;                       %Make sure sample faster than resolution
Packet_Rec = 0;
Packet_Error = 0;

%Log file name and column titles 
Logging = 1; %Set this to turn the data log on/off
Log_Title = 'VehicleSimLog_SystemCheckoff1.txt';
fileID = fopen(Log_Title,'w');
fprintf(fileID,'%s,%s,%s,%s,%s,%s,%s,%s,%s:\r\n','Time(s)','Base Torque','Torque Right','Torque Left','Steering Angle Binary','Velocity of Vehicle (mph)','Speed Calculated at Wake-up', 'Packets Recieved','Packet With Errors');

%Other User Defined Properties
plotTitle = 'Vehicle Speed vs Time';        %Plot title
xLabel = 'Elapsed Time(s)';                 %X-axis label
yLabel = 'Current Vehicle Velocity (mph)';  %Y-axis label
plotGrid = 'on';                            %'off' to turn off grid
scrollWidth = 10;                           %Display period in plot, plot entire data log if <= 0

%Choose which input float to graph (float_to_graph,then
%indicate the maximum and minimum value that it can be.
float_to_graph = 1;                         %Define which float to graph     
min = 0;                                    %Define y-min
max = 45;                                  %Define y-max

%Define Function Variables
time = zeros(1,1000);
data = zeros(1,1000);
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

try

    %Create and Configure Serial COM Port with user settings
    s = serial(serialPort);
    set(s,'Terminator','G');
    set(s,'BaudRate', baudrate);
    set(s,'DataBits', 8);
    set(s,'Parity','none');
    set(s,'StopBits', 1);
    set(s,'FlowControl','none');
    set(s,'InputBufferSize', num_of_bytes+1);
    set(s,'OutputBufferSize', 5);
    set(s,'BytesAvailableFcnCount', num_of_bytes+1);
    set(s,'BytesAvailableFcnMode','byte');
    set(s,'Timeout', 0.01);

    %Open the Serial Com Port and allow to open (pause)
    fopen(s);
    pause(1);

    %Set the internal timer at the execution of the 'tic' command. 
    %This timer's value can be accessed as by a subsequent call to 'toc'. 
    tic    

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %   Configuration for test, read below for options.    
    %    "How data should be sent back out on UART"
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %Send As String(1) or Uchar(0)
    String = 1;
    %Recieve As Float32(1) or Uchar Array(0)
    Float = 1;
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   

    %Loop when Plot is Active 
    while ishandle(plotGraph)

        %Increment the count and time for live graph
        count = count + 1;
        time(count) = toc;                                   
        %Extract Elapsed Time
        if(count > 2)
            dt = (time(count)-time(count-1));
        end

        CheckPacket = fread(s, 1, 'char');
        %Make sure incoming data contains the correct "set current command 'S'."
        if(CheckPacket == 'S')
            CheckPacket = 0;
            Rx_data_packet = fread(s, num_of_in_float, 'float32');       
            %Read data off the serial bus as 32-bit floats.      
            Base_Torque = Rx_data_packet(1);
            Set_Torque_Right = Rx_data_packet(2);
            Set_Torque_Left =  Rx_data_packet(3);
            Steering_Angle_Bin = Rx_data_packet(4);

            %Make sure read data is a Float and not an empty array
            if(~isempty(Rx_data_packet))
                Packet_Rec = Packet_Rec+1;
                Imset = Rx_data_packet(1);

                %Calculate back EMF at the current linear speed, current 
                %voltage available, then lastly, the (Maximum current) the 
                %motor can accept at the given speed (Maximum velocity).                    
                Vemf = (Vxi*Cemf);
                if(Vemf < Vbatt)
                    Vcurr = Vbatt - Vemf;                
                    Pcurr = Vcurr*Im;
                else
                    Imax = 200/Vbatt;
                    %fprintf('Motor Max Speed Reached')
                end
                %Check if current power is less than the available motor
                %power, if not set current to maximum available.                     
                if(Pmax-Pcurr > 0 && Vemf < Vbatt)
                    Imax = (Pmax-Pcurr)/Vbatt;
                end

                if(Imset > Imax)
                   %fprintf('Target Current Too High') 
                   Im = Imax;
                else
                    Im = Imset;
                end
            end
        elseif(CheckPacket == 'V')
            CheckPacket = 0;
            fprintf('Current Vehicle Speed: %f\n\n', Vxfmph)
            Speed = fread(s, 1, 'float32')
            fprintf('Speed recieved from Microcontroller/Calculated Speed: %f\n\n', Speed)
            fprintf(fileID,'**Microcontroller Awake! Current Speed: %f MPH **\n\n',Speed);
            percent_error = abs((Speed-Vxfmph)/Vxfmph)*100
            fprintf('Error in Calculation: %f % **\n\n',percent_error)
            fprintf(fileID,'**Error in Calculation: %f % **\n\n',percent_error);
            fprintf(fileID,'\r\n');
            Im = 0;
        else
            Im = 0;
            fprintf('Packet Error. Setting current to zero');
            Packet_Error = Packet_Error+1;
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
        N = (Fzr + Fzf); %Normal force of vehicle                          
        Fxr = m*((2*B*Im*L*r)/(((Jl/R)*G)+((Jm/R)*(1/G)))); %Force exerted from the motor on the rear wheel
        Fx = (Fxf + Fxr); %Net Force propelling the vehicle forward, sum of the forces applied by each wheel  
        Ff = N*Kincf; %Force of kenetic friction on vehicle in motion
        Fd = -0.5*Cd*p*A*(Vxi^2); %Aerodynamic drag force (N) acting in oposition to the direction of motion
        Fnet = Fx + Ff + Fd - (m*g*sin(beta)); %Net force acting on vehicle

        Ax = (Fnet)/m; %Current acceleration of vehicle, Net force acting on the vehicle divided by the mass of the vehicle

        Vxd = dt*Ax; %Acceleration times change in time equals the change in velocity
        Vxf = Vxi + Vxd; %Initial velocity plus the change in velocity equals final velocity

        %If the vehicle is stationary, stay at Omph
        if(Vxf - Vxi < 0 && Vxf < 0)
            Vxf = 0;
        end
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        %Convert the current speed to MPH
        Vxfmph = 2.23694*(Vxf);
        Current_Speed = Vxfmph
        Max_Current = Imax;
        Set_Current = Imset;
        Motor_Current = Im;      

        %Send current speed out to speed sensor
        if(String == 1)
            SendString = num2str(Vxfmph,'%.1f');
            SendString;
            fprintf(s,'%s',SendString);
            fwrite(s, 'G', 'char');
        end
        if(String == 0)
            SendUChar = num2str(Vxfmph,'%.1f');
            SendUChar;
            fwrite(s,SendUChar,'char');
            fwrite(s, 'G', 'char');
        end
        %pause(delay)               
        %time(count) - time(count-1);
        
        if(Logging == 1)
            %Save all input floats to the log file,
            %first with the current time, followed
            %by all of the read floats, ending with
            %a new-line. Log is CSV compatable.
            fprintf(fileID,'%f,',toc);
            fprintf(fileID,'%f,',Base_Torque);
            fprintf(fileID,'%f,',Set_Torque_Right);
            fprintf(fileID,'%f,',Set_Torque_Left);
            fprintf(fileID,'%f,',Steering_Angle_Bin);            
            fprintf(fileID,'%f,',Vxfmph);
            fprintf(fileID, '%f,', Speed);
            fprintf(fileID, '%f,', Packet_Rec);                       
            fprintf(fileID, '%f.', Packet_Error);            
            fprintf(fileID,'\r\n');
        end
        %Allow MATLAB time to Update Plot

        %Extract user selected data to graph
        data(count) = Vxfmph;
        Vxi = Vxf;

        %Plot some given data               
        %Adjust the graph's X-axis according to Scroll Width'.
        %It is adjusted using the current 'time' and 'count'.
        if(scrollWidth > 0)
            set(plotGraph,'XData',time(time > time(count)-scrollWidth),'YData',data(time > time(count)-scrollWidth));
            axis([time(count)-scrollWidth time(count) min max]);                
        %Plot the given float without adjusting for 'Scroll Width'
        else
            set(plotGraph,'XData',time,'YData',data);
            axis([0 time(count) min max]);
        end   
        pause(delay);
        
        if  ~mod(Packet_Rec,40)
            flushinput(s);
        end
    end

catch ME
   fclose(s);
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