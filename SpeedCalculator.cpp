/*
 * SpeedCalculator.cpp
 *
 *  Created on: Feb 18, 2013
 *      Author: wkb6223
 */

#include "SpeedCalculator.h"

#include "PulseEvent.h"
#include "SetKilometerEvent.h"
#include "TireSizeEvent.h"
#include "UpdateSpeedEvent.h"
#include <pthread.h>
#include <unistd.h>


SpeedCalculator::SpeedCalculator(Dispatcher* dispatch){
	REC_TYPE = rec::sc;
	input = 0;
	setUp = false;
	calc = true;
	SpeedCalculator::setDispatcher(dispatch);
	sub(ev::PULSES, this);
	sub(ev::TIRE_SIZE, this);
	sub(ev::KILO, this);
	initSpeeds();
}

void SpeedCalculator::notify(Event* event){
	if (event->getEventType() == ev::PULSES){
		((PulseEvent*)event)->run(this);
	} else if (event->getEventType() == ev::KILO){
		((SetKilometerEvent*)event)->run(this);
	} else if (event->getEventType() == ev::TIRE_SIZE){
		((TireSizeEvent*)event)->run(this);
	}
}

void SpeedCalculator::initSpeeds(){
	for (int i = 0; i < 300; i++){
		speeds[i] = 0;
	}
}

void SpeedCalculator::addSpeed(int speed){
	input++;
	for (int i = 299; i > 0; i--){
		speeds[i] = speeds[i-1];
	}
	speeds[0] = speed;
}

double SpeedCalculator::getCurrentSpeed(){
	int pulseCount = 0;
	pulseCount = pulseCount + speeds[0];
	pulseCount = pulseCount + speeds[1];
	pulseCount = pulseCount + speeds[2];
	double curSpeed = ((double)pulseCount)/3.0;
	curSpeed = clacSpeed(curSpeed);
	return curSpeed;
}

double SpeedCalculator::clacSpeed(double count){
	double speed = count;
	speed = ((speed*tireSize)*60*60)/100000;
	if (!kilo) {
		speed = speed / 1.60934;
	}
	return speed;
}

void SpeedCalculator::setTireSize(int tire){
	printf("tireSet\n");
	tireSize = tire;
	setUp = true;
}

void SpeedCalculator::setKilo(bool isKilo){
	printf("kiloSet\n");
	kilo = isKilo;
}

bool SpeedCalculator::isSetUp(){
	return setUp;
}

void* checkSpeed(void* sc){
	SpeedCalculator* speedCalc = (SpeedCalculator*)sc;
	while (true){
		if(speedCalc->isSetUp()){
			Event* event = speedCalc->getSpeed();
			speedCalc->trigger(event);
			usleep(1000000);
		}
	}
	return NULL;
}

double SpeedCalculator::getAverageSpeed(){
	double total = 0;
	if (input == 0){
		total = 0.0;
	} else if(input < 300){
		for (int i = 0; i < input; i++){
			total = total + speeds[i];
		}
		total = total/input;
	} else {
		for (int i = 0; i < 300; i++){
			total = total + speeds[i];
		}
		total = total/300;
	}

	return clacSpeed(total);
}

Event* SpeedCalculator::getSpeed(){
	double current = getCurrentSpeed();
	double average = getAverageSpeed();
	UpdateSpeedEvent* use = new UpdateSpeedEvent();
	use->setAverage(average);
	use->setCurrent(current);
	return use;
}

void SpeedCalculator::genSpeed(){
	pthread_t speed_t;
	pthread_create(&speed_t, NULL, checkSpeed, this);
}

