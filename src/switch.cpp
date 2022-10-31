// Description: This file implements the initialization of a switch with external interrupts enabled
//----------------------------------------------------------------------//
#include "switch.h"
#include <avr/io.h>

/*
 * Initializes pull-up resistor on PD0 and sets it into input mode (Pin 21)
 * Also enables external interrupts for INT0
 */
void initSwitchPD0(){

  DDRD &= ~(1<<DDD0); // set direction for input
  PORTD |= (1 << PORTD0);  // enable the pullup resistor for stable input

  // Enable external interrupts for any logical change
  EICRA &=  ~( 1 << ISC01);
  EICRA |=  ( 1 << ISC00);

  // enable the external interrupt mask register so that INT0 bit is enabled for interrupts
  EIMSK |= ( 1 << INT0);
  
}