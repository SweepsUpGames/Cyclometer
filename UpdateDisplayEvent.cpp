/*
 * UpdateDisplayEvent.cpp
 *
 *  Created on: Feb 12, 2013
 *      Author: wkb6223
 */

#include "UpdateDisplayEvent.h"
#include "SevenSegmetController.h"

UpdateDisplayEvent::UpdateDisplayEvent(double startCurrent, double startAverage){
	current = startCurrent;
	average = startAverage;
}

void UpdateDisplayEvent::run(SevenSegmetController* ssc){
	ssc->setDisplay(current, average);
}
