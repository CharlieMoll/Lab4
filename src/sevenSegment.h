#ifndef SEVENSEGMENT_H
#define SEVENSEGMENT_H

// Initialize the seven segment display
void initSevenSegment();

// Turn off all LEDs
void clearDisplay();

// Handler to process number passed in. Expected to be between 0 and 9
void toggleDisplay(int num);

// Turn on the proper LEDs for each of the numbers 0-9
void setZero();

void setOne();

void setTwo();

void setThree();

void setFour();

void setFive();

void setSix();

void setSeven();

void setEight();

void setNine();

#endif