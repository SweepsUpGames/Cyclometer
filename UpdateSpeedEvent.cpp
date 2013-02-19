/*
 * UpdateSpeedEvent.cpp
 *
 *  Created on: Feb 18, 2013
 *      Author: wkb6223
 */

#include "UpdateSpeedEvent.h"

UpdateSpeedEvent::UpdateSpeedEvent(){
	EVENT_TYPE = ev::SPEED;
}

void UpdateSpeedEvent::run(Receiver* rec){

}

void UpdateSpeedEvent::setAverage(double newAverage){
	average = newAverage;
}

void UpdateSpeedEvent::setCurrent(double newCurrent){
	current = newCurrent;
}

double UpdateSpeedEvent::getAverage(){
	return average;
}

double UpdateSpeedEvent::getCurrent(){
	return current;
}
