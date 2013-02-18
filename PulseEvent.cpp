/*
 * PulseEvent.cpp
 *
 *  Created on: Feb 18, 2013
 *      Author: wkb6223
 */

#include "PulseEvent.h"

PulseEvent::PulseEvent(){
	EVENT_TYPE = ev::PULSES;
}

PulseEvent::~PulseEvent(){

}

void PulseEvent::setPulses(int newPulses){
	pulses = newPulses;
}

void PulseEvent::run(Receiver* rec){

}
