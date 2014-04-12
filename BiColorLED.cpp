/*  Simple Bicolor LED library for Arduino, v1.4
    Copyright (C) 2014 Wolfgang Faust

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
	color1=0;
	color2=0;
	blinkSpeed1=0;
	blinkSpeed2=0;
	yellowRed=false;
	blinkOne=true;
}

void BiColorLED::setColor(uint8_t toColor) {
	setColor(toColor, 0);
}
void BiColorLED::setColor2(uint8_t toColor) {
	setColor(color1, toColor);
}
void BiColorLED::setColor(uint8_t toColor1, uint8_t toColor2) {
	color1=toColor1;
	color2=toColor2;
	drive(); // Change the color
}

uint8_t BiColorLED::getColor() {
	return color1;
}
uint8_t BiColorLED::getColor2() {
	return color2;
}

void BiColorLED::setBlinkSpeed(unsigned long toSpeed) {
	setBlinkSpeed(toSpeed, toSpeed);
}
void BiColorLED::setBlinkSpeed(unsigned long toSpeed1, unsigned long toSpeed2) {
	blinkSpeed1=toSpeed1;
	blinkSpeed2=toSpeed2;
	lastBlink=millis();
	drive();
}

unsigned long BiColorLED::getBlinkSpeed() {
	return blinkSpeed1;
}
unsigned long BiColorLED::getBlinkSpeed2() {
	return blinkSpeed2;
}

void BiColorLED::drive() {
	uint8_t tmpcolor; // Create a temporary color variable
	if (blinkSpeed1 == 0) {
		tmpcolor=color1;
	} else {
		unsigned long blinkSpeed;
		if (blinkOne) {
			blinkSpeed = blinkSpeed1;
		} else {
			blinkSpeed = blinkSpeed2;
		}
		if (millis() - lastBlink >= blinkSpeed) {
			blinkOne=!blinkOne;
			lastBlink += blinkSpeed;
		}
		tmpcolor=blinkOne?color1:color2;
	}
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
