#include <avr/io.h>
#include <avr/interrupt.h>
#include <Arduino.h>
#include "sevenSegment.h"
#include "switch.h"
#include "pwm.h"
#include "adc.h"
#include "timer.h"

// Implement state machine as an enum
typedef enum stateType_enum {
  wait_press, debounce_press, wait_release, debounce_release, nine, eight, seven, six, five, four, three, two, one, zero
} stateType;

// Variables that are accessed in the ISR
volatile stateType state = wait_press;
volatile bool active = true;

int main() {

  // Enable interrupts
  sei();
  // Initialize components
  initSwitchPD0();
  initSevenSegment();
  initPWMTimer3();
  initPWMTimer4();
  initADC0();
  unsigned int result;
  

  // Loop
  while(1) {

    // Process state machine's current state
    switch (state) {

      // If waiting for press, do nothing
      case wait_press:
        // TODO: Handle ADC conversion to control motor via PWM duty cycle
        result = ADCL;
        result += ((unsigned int) ADCH) << 8;
        changeDutyCycle(result);
        clearDisplay();
        break;

      // If in debounce state, delay for 1 ms to avoid issues, then progress to waiting for release
      case debounce_press:
        delayMs(1);
        state = wait_release;
        break;

      // If waiting for release, do nothing
      case wait_release:
        break;
      
      // If in release debounce state, delay for 1 ms to avoid issues, then progress to waiting for press
      case debounce_release:
        delayMs(1);
        state = nine;
        break;

      // For each state 9 through 0, desplay the correct number and then wait a second before transitioning to the next state
      case nine: 
        // Turn motor off 
        result = (1023 * 0.5);
        changeDutyCycle(result);
        toggleDisplay(9);
        delayS(1);
        state = eight;
        break;

      case eight: 
        toggleDisplay(8);
        delayS(1);
        state = seven;
        break;

      case seven: 
        toggleDisplay(7);
        delayS(1);
        state = six;
        break;

      case six: 
        toggleDisplay(6);
        delayS(1);
        state = five;
        break;

      case five: 
        toggleDisplay(5);
        delayS(1);
        state = four;
        break;

      case four: 
        toggleDisplay(4);
        delayS(1);
        state = three;
        break;

      case three: 
        toggleDisplay(3);
        delayS(1);
        state = two;
        break;

      case two: 
        toggleDisplay(2);
        delayS(1);
        state = one;
        break;

      case one: 
        toggleDisplay(1);
        delayS(1);
        state = zero;
        break;

      // Once zero is displayed, make the active flag true again to allow the button to be pressed, and the continue back to the original state
      case zero: 
        toggleDisplay(0);
        delayS(1);
        state = wait_press;
        active = true;
        break;
    }
  }
return 0;
}

// ISR for external interrupt from switch
ISR(INT0_vect) {

  // Active flag determines whether or not countdown is currently in progress
  if (!active) {
    return;
  }

   // If interrupt occurred while waiting for a press, then go to press debounce state
  if (state == wait_press) {
    state = debounce_press;
  }

  // Otherwise, button must have been released
  else if (state == wait_release) {

    // Progress to debounce state
    state = debounce_release;
    active = false;
  
  }
}
