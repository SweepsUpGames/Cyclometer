/*
 * UpdateElapcedTimeEvent.cpp
 *
 *  Created on: Feb 19, 2013
 *      Author: wkb6223
 */

#include "UpdateElapcedTimeEvent.h"
#include "SevenSegmetController.h"

UpdateElapcedTimeEvent::UpdateElapcedTimeEvent(){
	EVENT_TYPE = ev::DISPLAY;
}

void UpdateElapcedTimeEvent::run(Receiver* rec){
	if (rec->getRecType() == rec::ssc){
		((SevenSegmetController*)rec)->setDisplay(minutes,seconds);
	}
}

void UpdateElapcedTimeEvent::setMinutes(int min){
	minutes = min;
}

void UpdateElapcedTimeEvent::setSeconds(int sec){
	seconds = sec;
}
