#include "motor.hpp"

// Motor connections
int en = 11;
int in1 = 10;
int in2 = 9;

int dir = 0;  // Define variables for motor direction and speed
int spd = 0;

void setup() {
  // Set all the motor control pins to outputs
    DDRB |= (1 << DDB5) | (1 << DDB4);
    DDRH |= (1 << DDH6);
}
void loop() {
      int potInput = analogRead(A0);  // Read potentiometer value
  spd = map(abs(potInput - 512), 0, 512, 0, 255); // Calculate motor speed, pot travel from midpoint
  if (potInput > 512) // Compare to potentiometer midpoint to get motor direction
    dir = 0;
  else
    dir = 1;
    driveMotor();
}
void driveMotor(){
  if (dir)
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  }
  else
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  }
  analogWrite(en, spd);
}

void setDir(int in) {
  dir = in;
}