/*
 * UpdateDisplayDistanceEvent.cpp
 *
 *  Created on: Feb 19, 2013
 *      Author: wkb6223
 */

#include "UpdateDisplayDistanceEvent.h"
#include "SevenSegmetController.h"

UpdateDisplayDistanceEvent::UpdateDisplayDistanceEvent(){
	EVENT_TYPE = ev::DISPLAY;
}

void UpdateDisplayDistanceEvent::run(Receiver* rec){
	if(rec->getRecType() == rec::ssc){
		((SevenSegmetController*)rec)->setDisplay(dist);
	}
}

void UpdateDisplayDistanceEvent::setDist(double distance){
	dist = distance;
}
