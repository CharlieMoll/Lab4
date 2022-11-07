// Description: This file implements the initialization of a seven segment display that uses
// PC0-7 (Pins 22-29), and also provides functionality to display all digits 0-9
//----------------------------------------------------------------------//
#include <avr/io.h>
#include "sevenSegment.h"

void initSevenSegment() {

    // Set all pins as outputs
    DDRC |= (1 << DDC0) | (1 << DDC1) | (1 << DDC2) | (1 << DDC3) | (1 << DDC4) | (1 << DDC5) | (1 << DDC6) | (1 << DDC7);

}

void clearDisplay() {
    // Set all pins to 0 to turn off all LEDs
    PORTC &= ~((1 << PORTC0) | (1 << PORTC1) | (1 << PORTC2) | (1 << PORTC3) | (1 << PORTC4) | (1 << PORTC5) | (1 << PORTC6) | (1 << PORTC7));
}

void toggleDisplay(int num) {

    // Call the correct helper function to display an integer based on the input passed in
    switch (num) {

        case 0: setZero(); break;

        case 1: setOne(); break;

        case 2: setTwo(); break;

        case 3: setThree(); break;

        case 4: setFour(); break;

        case 5: setFive(); break;

        case 6: setSix(); break;

        case 7: setSeven(); break;

        case 8: setEight(); break;

        case 9: setNine(); break;

    }
}

/*
Seven segment configurations for LEDs A-H are as follows (LED H is the decimal point)
{A,B,C,D,E,F,G,H}:
{1,1,1,1,1,1,0,0} //0
{0,1,1,0,0,0,0,0} //1
{1,1,0,1,1,0,1,0} //2
{1,1,1,1,0,0,1,0} //3
{0,1,1,0,0,1,1,0} //4
{1,0,1,1,0,1,1,0} //5
{1,0,1,1,1,1,1,0} //6
{1,1,1,0,0,0,0,0} //7
{1,1,1,1,1,1,1,0} //8
{1,1,1,1,0,1,1,0} //9
*/

void setZero() {
    PORTC |= (1 << PORTC0) | (1 << PORTC1) | (1 << PORTC2) | (1 << PORTC3) | (1 << PORTC4) | (1 << PORTC5);
    PORTC &= ~((1 << PORTC6) | (1 << PORTC7));
}

void setOne() {
    PORTC |= (1 << PORTC1) | (1 << PORTC2);
    PORTC &= ~((1 << PORTC0) | (1 << PORTC3) | (1 << PORTC4) | (1 << PORTC5) | (1 << PORTC6) | (1 << PORTC7));    
}

void setTwo() {
    PORTC |= (1 << PORTC0) | (1 << PORTC1) | (1 << PORTC3) | (1 << PORTC4) | (1 << PORTC6);
    PORTC &= ~((1 << PORTC2) | (1 << PORTC5) | (1 << PORTC7)); 
}

void setThree() {
    PORTC |= (1 << PORTC0) | (1 << PORTC1) | (1 << PORTC2) | (1 << PORTC3) | (1 << PORTC6);
    PORTC &= ~((1 << PORTC4) | (1 << PORTC5) | (1 << PORTC7));
}

void setFour() {
    PORTC |= (1 << PORTC1) | (1 << PORTC2) | (1 << PORTC5) | (1 << PORTC6);
    PORTC &= ~((1 << PORTC0) | (1 << PORTC3) | (1 << PORTC4) | (1 << PORTC7));
}

void setFive() {
    PORTC |= (1 << PORTC0) | (1 << PORTC2) | (1 << PORTC3) | (1 << PORTC5) | (1 << PORTC6);
    PORTC &= ~((1 << PORTC1) | (1 << PORTC4) | (1 << PORTC7));
}

void setSix() {
    PORTC |= (1 << PORTC0) | (1 << PORTC2) | (1 << PORTC3) | (1 << PORTC4) | (1 << PORTC5) | (1 << PORTC6);
    PORTC &= ~((1 << PORTC1) | (1 << PORTC7));
}

void setSeven() {
    PORTC |= (1 << PORTC0) | (1 << PORTC1) | (1 << PORTC2);
    PORTC &= ~((1 << PORTC3) | (1 << PORTC4) | (1 << PORTC5) | (1 << PORTC6) | (1 << PORTC7));
}

void setEight() {
    PORTC |= (1 << PORTC0) | (1 << PORTC1) | (1 << PORTC2) | (1 << PORTC3) | (1 << PORTC4) | (1 << PORTC5) | (1 << PORTC6);
    PORTC &= ~((1 << PORTC7));
}

void setNine() { 
    PORTC |= (1 << PORTC0) | (1 << PORTC1) | (1 << PORTC2) | (1 << PORTC3) | (1 << PORTC5) | (1 << PORTC6);
    PORTC &= ~((1 << PORTC4) | (1 << PORTC7));
}

