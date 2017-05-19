                Vemf = (Vxi*Cemf)
                Vcurr = Vbatt - Vemf             
                Pcurr = Vcurr*Im
                
                if(Pmax-Pcurr > 0 && Vcurr > 0)
                   
                    Imax = (Pmax-Pcurr)/Vbatt
                else
                    Imax = 0
                    fprintf('Motor Max Speed Reached')
                end
                %Check if current power is less than the available motor
                %power, if not set current to maximum available.                     
                if(Imset > Imax)
                   fprintf('Target Current Too High') 
                   Im = Imax
                else
                   Im = Imset
                end
            end
            
                
                                Vemf = (Vxi*Cemf)
                Vcurr = Vbatt - Vemf             
                Pcurr = Vcurr*Im
                
                if(Pmax-Pcurr > 0 && Vcurr > 0)
                    
                    Imax = (Pmax-Pcurr)/Vbatt
                else
                    Imax = 0
                    fprintf('Motor Max Speed Reached')
                end
                %Check if current power is less than the available motor
                %power, if not set current to maximum available.                     
                if(Imset > Imax)
                   fprintf('Target Current Too High') 
                   Im = Imax
                else
                    Im = Imset
                end
            end