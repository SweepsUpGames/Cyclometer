/*
 * DistanceCalculator.cpp
 *
 *  Created on: Feb 19, 2013
 *      Author: wkb6223
 */

#include "DistanceCalculator.h"
#include "PulseEvent.h"
#include "SetKilometerEvent.h"
#include "UpdateDisplayDistanceEvent.h"
#include "TireSizeEvent.h"

#include <pthread.h>
#include <unistd.h>

DistanceCalculator::DistanceCalculator(Dispatcher* dispatch){
	DistanceCalculator::setDispatcher(dispatch);
	REC_TYPE = rec::dc;
	setUp = false;
	calc = true;
	totalDist = 0.0;
	//sub(ev::PULSES, this);
	//sub(ev::TIRE_SIZE, this);
	//sub(ev::KILO, this);
}

void DistanceCalculator::addPulse(int pulses){
	if (calc){
		totalDist = totalDist + calcDist(pulses);
	}
}

void DistanceCalculator::setKilo(bool kilo){
	km = kilo;
}

void DistanceCalculator::setTireSize(int tire){
	tireSize = tire;
	setUp = true;
}

double DistanceCalculator::calcDist(int pulses){
	double dist = (pulses * tireSize)/100000;
	return dist;
}

void DistanceCalculator::notify(Event* event){
	if (event->getEventType() == ev::PULSES){
		((PulseEvent*)event)->run(this);
	} else if (event->getEventType() == ev::KILO){
		((SetKilometerEvent*)event)->run(this);
	} else if (event->getEventType() == ev::TIRE_SIZE){
		((TireSizeEvent*)event)->run(this);
	}
}

Event* DistanceCalculator::makeEvent(){
	UpdateDisplayDistanceEvent* update = new UpdateDisplayDistanceEvent();
	update->setDist(totalDist);
	//return update;
	return NULL;
}

void* checkDist(void* dc){
	DistanceCalculator* dist = ((DistanceCalculator*)dc);
	while (true){
		Event* event = dist->makeEvent();
		dist->trigger(event);
		usleep(1000000);
	}
	return NULL;
}

void DistanceCalculator::genDist(){
	pthread_t dist_t;
	pthread_create(&dist_t, NULL, checkDist, this);
}
