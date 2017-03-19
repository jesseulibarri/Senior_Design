
#include <avr/io.h>
#include <math.h>
#include "system_init.h"
#include "speed.h"
#include "steering.h"

#define COUNT_PERIOD    0.016F

/*****************************************************************************
 * Name: Exponential Moving Average
 *  
 * Description: This function 
 * **************************************************************************/
//Exponential Moving Average
#define N 10
float ema(float avg, float sample)
{
    float alpha = 2.0/(N+1);
    avg = alpha * sample + (1.0-alpha) * avg;
    return avg;
}


/**************************************************************************************
 * Name: calc_speed
 *
 * Description: Calculates the speed based on the incoming speed sensor pulse.
 *************************************************************************************/
float calc_speed(uint16_t time_dif, float current_avg) {

    PORTC |= (1 << PC0);

//    static uint16_t timestamp_avg_dif;

//    timestamp_avg_dif = calc_avg(timestamps);
    float msec = (float)time_dif * COUNT_PERIOD;
    float seconds = msec / 1000;
    float new_speed = (distance_per_pulse/ seconds) * (1 / 17.6);
    float new_avg = ema(current_avg, new_speed); 

    PORTC &= ~(1 << PC0);

return new_avg;
}//calc_speed


/**************************************************************************************************
 * Name: set_differential_torque
 *
 * Description: This funcion is has 3 input arguments all which are passed by pointer
 *	reference beccause these arguments are modified in the function. This function
 *	is used to calculate a torque ration between the rear wheels of the car based
 *	on a steering angle. As well this function inlcudes an acceleration mode which
 * 	is used to ramp up the speed of the care while still checking if the car is 
 *	turning left and right to calculate a difference in torque (electronic differential).
 *	This function also implements a safety feature that doesnt let the torque ramp up
 *	past a set max torque value which can be changed.
 ***************************************************************************************************/

void set_differential_torque(float* torque_right, float* torque_left, uint16_t angle, float b_torque){
    
    float torque_ratio;

    //We are turning right
    if(angle >= 0 && angle <= 2048){
        torque_ratio = ((-0.00031)*angle)+(0.99972);	//Calculate torque ratio
        *torque_right = b_torque*torque_ratio;	//Update right motor torque
        *torque_left = b_torque;			//Update left motor torque
    }
    //We are turning left
    else{
        torque_ratio = ((1.033)*log((double)angle))-(7.59);	//Log function takes a double so had to typecast
        *torque_left = b_torque*torque_ratio;		//Update left motor torque
        *torque_right = b_torque;				//Update right motor torque
    }
}//set_differential_torque


/**************************************************************************************************
 * Name: cruise
 *
 * Description: 
 ***************************************************************************************************/

void cruise(float* torque_right, float* torque_left, uint16_t angle, float* b_torque, float target_speed, float current_speed, float* integral){
    float torque_ratio;    
    float error = 0; 
    float iteration_time = 0.100;
    float Kp = 0.75;
    float Ki = 0.5;
    float bias = 0.2;
    float output;


    error = target_speed - current_speed;
    *integral = *integral + (error*iteration_time);
   // derivative = (error - error_prior)/iteration_time;
    output = Kp*error + Ki*(*integral) + bias;    
   // error_prior = error;
  
    if(output < 0){
        *b_torque = 0;
    }
    else{
        *b_torque =  output;
    }

    
    //We are turning right
    if(angle >= 0 && angle <= 2048){
        torque_ratio = ((-0.00031)*angle)+(0.99972);	//Calculate torque ratio
        *torque_right =(*b_torque)*torque_ratio;	//Update right motor torque
        *torque_left = (*b_torque);			//Update left motor torque
    }
    //We are turning left
    else{
        torque_ratio = ((1.033)*log((double)angle))-(7.59);	//Log function takes a double so had to typecast
        *torque_left = (*b_torque)*torque_ratio;		//Update left motor torque
        *torque_right = *b_torque;				//Update right motor torque
    }
   // set_differential_torque(torque_right, torque_left, angle, b_torque);
}//cruise


