
#include "const.h"
#include <avr/math.h>


double tire_circ = tire_diam * M_PI;
double distance_per_pulse = tire_circ / sprocket_teeth;

