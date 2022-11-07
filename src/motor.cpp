#include "motor.hpp"

void setup() {
  // Set all the motor control pins to outputs
    DDRB |= (1 << DDB5) | (1 << DDB4);
    DDRH |= (1 << DDH6);
}

void setDirection(int direction) {

  if (direction == 1) {
    PORTB |= (1 << DDB5);
    PORTB &= ~(1 << DDB4);
  }

  else {
    PORTB |= (1 << DDB4);
    PORTB &= ~(1 << DDB5);
  }

}