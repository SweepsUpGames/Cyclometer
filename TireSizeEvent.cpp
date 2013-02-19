/*
 * TireSizeEvent.cpp
 *
 *  Created on: Feb 18, 2013
 *      Author: wkb6223
 */

#include "TireSizeEvent.h"
#include "SpeedCalculator.h"

TireSizeEvent::TireSizeEvent(){
	EVENT_TYPE = ev::TIRE_SIZE;
}

void TireSizeEvent::run(Receiver* rec){
	if (rec->getRecType() == rec::sc){
		((SpeedCalculator*)rec)->setTireSize(tireSize);
	} else if (rec->getRecType() == rec::dc){
		((SpeedCalculator*)rec)->setTireSize(tireSize);
	}
}

void TireSizeEvent::setTireSize(int tire){
	tireSize = tire;
}
