/*
 * PulseEvent.cpp
 *
 *  Created on: Feb 18, 2013
 *      Author: wkb6223
 */

#include "PulseEvent.h"
#include "SpeedCalculator.h"
#include "DistanceCalculator.h"

PulseEvent::PulseEvent(){
	EVENT_TYPE = ev::PULSES;
}

PulseEvent::~PulseEvent(){

}

void PulseEvent::setType(ev::EventType et){
	EVENT_TYPE = et;
}

void PulseEvent::setPulses(int newPulses){
	pulses = newPulses;
}

void PulseEvent::run(Receiver* rec){
	if (rec->getRecType() == rec::sc){
		((SpeedCalculator*)rec)->addSpeed(pulses);
	} else if (rec->getRecType() == rec::dc){
		((DistanceCalculator*)rec)->addPulse(pulses);
	}
}
