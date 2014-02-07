/*  Simple Bicolor LED library for Arduino, v1.0
    Copyright (C) 2012 Wolfgang Faust

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    
    Email: wolf@wolfgang.site40.net
*/
#include "BiColorLED.h"

BiColorLED::BiColorLED(uint8_t ledPin1, uint8_t ledPin2) {
	pin1=ledPin1;
	pin2=ledPin2;
	pinMode(pin1, OUTPUT);
	pinMode(pin2, OUTPUT);
	color=0;
	yellowRed=false;
}

void BiColorLED::setColor(uint8_t toColor) {
	color=toColor;
	drive(); // Change the color
}

uint8_t BiColorLED::getColor() {
	return color;
}

void BiColorLED::drive() {
	uint8_t tmpcolor = color; // Create a temporary color variable
	// TODO blinking goes here
	if (tmpcolor == 3) { // Yellow
		tmpcolor = (yellowRed?1:2);
		yellowRed = !yellowRed;
	} // Beyond this point the color is always red, green, or black
	// Actual LED driving
	if (tmpcolor == 1) { // Red
		digitalWrite(pin1, HIGH);
		digitalWrite(pin2, LOW);
	} else if (tmpcolor == 2) { // Green
		digitalWrite(pin1, LOW);
		digitalWrite(pin2, HIGH);
	} else { // Black
		digitalWrite(pin1, LOW);
		digitalWrite(pin2, LOW);
	}
}
