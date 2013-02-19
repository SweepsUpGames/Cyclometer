/*
 * SetKilometerEvent.cpp
 *
 *  Created on: Feb 18, 2013
 *      Author: wkb6223
 */

#include "SetKilometerEvent.h"
#include "SpeedCalculator.h"
#include "DistanceCalculator.h"

SetKilometerEvent::SetKilometerEvent(){
	EVENT_TYPE = ev::KILO;
}

void SetKilometerEvent::run(Receiver* rec){
	if (rec->getRecType() == rec::sc){
		((SpeedCalculator*)rec)->setKilo(km);
	} else if (rec->getRecType() == rec::dc){
		((DistanceCalculator*)rec)->setKilo(km);
	}
}

void SetKilometerEvent::setKilometers(bool isKilometers){
	km = isKilometers;
}
