/*
 * TimeEvent.cpp
 *
 *  Created on: Feb 19, 2013
 *      Author: wkb6223
 */

#include "TimeEvent.h"

TimeEvent::TimeEvent(){
	EVENT_TYPE = ev::TIME;
}

void TimeEvent::run(Receiver* receiver){

}

void TimeEvent::setMinutes(int min){
	minutes = min;
}

void TimeEvent::setSeconds(int sec){
	seconds = sec;
}

int TimeEvent::getMinutes(){
	return minutes;
}

int TimeEvent::getSeconds(){
	return seconds;
}

