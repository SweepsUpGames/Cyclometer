/*
 * UpdateDisplayNumberEvent.cpp
 *
 *  Created on: Feb 18, 2013
 *      Author: wkb6223
 */

#include "UpdateDisplayNumberEvent.h"

UpdateDisplayNumberEvent::UpdateDisplayNumberEvent(){
	EVENT_TYPE = ev::DISPLAY;
}

void UpdateDisplayNumberEvent::setNumber(int newNumber){
	number = newNumber;
}

void UpdateDisplayNumberEvent::run(SevenSegmetController* ssc){
	ssc->setDisplay(number, leadingZeros);
}

void UpdateDisplayNumberEvent::setLeadingZeros(bool newLeadingZeros){
	leadingZeros = newLeadingZeros;
}
