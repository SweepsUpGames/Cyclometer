/*
 * UpdateDisplayEvent.cpp
 *
 *  Created on: Feb 12, 2013
 *      Author: wkb6223
 */

#include "UpdateDisplayEvent.h"
#include "SevenSegmetController.h"
#include "EventType.h"

UpdateDisplayEvent::UpdateDisplayEvent(){
    this.EVENT_TYPE = ev::DISPLAY;
}

void UpdateDisplayEvent::setCurrent(double newCurrent){
	current = newCurrent;
}

void UpdateDisplayEvent::setAverage(double newAverage){
	average = newAverage;
}

void UpdateDisplayEvent::run(SevenSegmetController* ssc){
	ssc->setDisplay(current, average);
}
