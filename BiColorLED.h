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
#ifndef BiColorLED_H
#define BiColorLED_H 1

#include "WProgram.h" 

class BiColorLED{
	public:
		BiColorLED(uint8_t ledPin1, uint8_t ledPin2);
		void drive();
		void setColor(uint8_t toColor);
		uint8_t getColor();
	private:
		uint8_t color;
		uint8_t pin1, pin2;
		bool yellowRed;
};
  
#endif
