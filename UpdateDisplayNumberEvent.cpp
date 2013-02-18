/*
 * UpdateDisplayNumberEvent.cpp
 *
 *  Created on: Feb 18, 2013
 *      Author: wkb6223
 */

#include "UpdateDisplayNumberEvent.h"
#include "SevenSegmetController.h"

UpdateDisplayNumberEvent::UpdateDisplayNumberEvent(){
	EVENT_TYPE = ev::DISPLAY;
}

void UpdateDisplayNumberEvent::setNumber(int newNumber){
	number = newNumber;
}

void UpdateDisplayNumberEvent::run(Receiver* rec){
	if(rec->getRecType() == rec::ssc){
		((SevenSegmetController*)rec)->setDisplay(number, leadingZeros);
	}
}

void UpdateDisplayNumberEvent::setLeadingZeros(bool newLeadingZeros){
	leadingZeros = newLeadingZeros;
}
