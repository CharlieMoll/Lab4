// Description: This file declares functions that utilize the timers 3
            //  and 4 PWM.
//----------------------------------------------------------------------//

#ifndef PWM_H
#define PWM_H

#include <avr/io.h>

void initPWMTimer3();
void initPWMTimer4();
void changeDutyCycle(unsigned int result);


#endif