// Description: This file implements the initialization of a seven segment display that uses
// PA0-7 (Pins 22-29), and also provides functionality to display all digits 0-9
//----------------------------------------------------------------------//
#include <avr/io.h>
#include "sevenSegment.h"

void initSevenSegment() {

    // Set all pins as outputs
    DDRA |= (1 << DDA0) | (1 << DDA1) | (1 << DDA2) | (1 << DDA3) | (1 << DDA4) | (1 << DDA5) | (1 << DDA6) | (1 << DDA7);

}

void clearDisplay() {
    // Set all pins to 0 to turn off all LEDs
    PORTA &= ~((1 << PORTA0) | (1 << PORTA1) | (1 << PORTA2) | (1 << PORTA3) | (1 << PORTA4) | (1 << PORTA5) | (1 << PORTA6) | (1 << PORTA7));
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
    PORTA |= (1 << PORTA0) | (1 << PORTA1) | (1 << PORTA2) | (1 << PORTA3) | (1 << PORTA4) | (1 << PORTA5);
    PORTA &= ~((1 << PORTA6) | (1 << PORTA7));
}

void setOne() {
    PORTA |= (1 << PORTA1) | (1 << PORTA2);
    PORTA &= ~((1 << PORTA0) | (1 << PORTA3) | (1 << PORTA4) | (1 << PORTA5) | (1 << PORTA6) | (1 << PORTA7));    
}

void setTwo() {
    PORTA |= (1 << PORTA0) | (1 << PORTA1) | (1 << PORTA3) | (1 << PORTA4) | (1 << PORTA6);
    PORTA &= ~((1 << PORTA2) | (1 << PORTA5) | (1 << PORTA7)); 
}

void setThree() {
    PORTA |= (1 << PORTA0) | (1 << PORTA1) | (1 << PORTA2) | (1 << PORTA3) | (1 << PORTA6);
    PORTA &= ~((1 << PORTA4) | (1 << PORTA5) | (1 << PORTA7));
}

void setFour() {
    PORTA |= (1 << PORTA1) | (1 << PORTA2) | (1 << PORTA5) | (1 << PORTA6);
    PORTA &= ~((1 << PORTA0) | (1 << PORTA3) | (1 << PORTA4) | (1 << PORTA7));
}

void setFive() {
    PORTA |= (1 << PORTA0) | (1 << PORTA2) | (1 << PORTA3) | (1 << PORTA5) | (1 << PORTA6);
    PORTA &= ~((1 << PORTA1) | (1 << PORTA4) | (1 << PORTA7));
}

void setSix() {
    PORTA |= (1 << PORTA0) | (1 << PORTA2) | (1 << PORTA3) | (1 << PORTA4) | (1 << PORTA5) | (1 << PORTA6);
    PORTA &= ~((1 << PORTA1) | (1 << PORTA7));
}

void setSeven() {
    PORTA |= (1 << PORTA0) | (1 << PORTA1) | (1 << PORTA2);
    PORTA &= ~((1 << PORTA3) | (1 << PORTA4) | (1 << PORTA5) | (1 << PORTA6) | (1 << PORTA7));
}

void setEight() {
    PORTA |= (1 << PORTA0) | (1 << PORTA1) | (1 << PORTA2) | (1 << PORTA3) | (1 << PORTA4) | (1 << PORTA5) | (1 << PORTA6);
    PORTA &= ~((1 << PORTA7));
}

void setNine() { 
    PORTA |= (1 << PORTA0) | (1 << PORTA1) | (1 << PORTA2) | (1 << PORTA3) | (1 << PORTA5) | (1 << PORTA6);
    PORTA &= ~((1 << PORTA4) | (1 << PORTA7));
}

