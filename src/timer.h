#ifndef TIMER_H
#define TIMER_H

#include <avr/io.h>

void initTimer1();
void delayMs(unsigned int delay);
void initTimer0();
void delayS(unsigned int delay); 

#endif