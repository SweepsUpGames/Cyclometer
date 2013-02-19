/*
 * TireSizeEvent.cpp
 *
 *  Created on: Feb 18, 2013
 *      Author: wkb6223
 */

#include "TireSizeEvent.h"
#include "SpeedCalculator.h"
#include "DistanceCalculator.h"

TireSizeEvent::TireSizeEvent(){
	EVENT_TYPE = ev::TIRE_SIZE;
}

void TireSizeEvent::setType(ev::EventType ev){
	EVENT_TYPE = ev;
}

void TireSizeEvent::run(Receiver* rec){
	if (rec->getRecType() == rec::sc){
		((SpeedCalculator*)rec)->setTireSize(tireSize);
	} else if (rec->getRecType() == rec::dc){
		((DistanceCalculator*)rec)->setTireSize(tireSize);
	}
}

void TireSizeEvent::setTireSize(int tire){
	tireSize = tire;
}
