/*
 * TimeCalculator.cpp
 *
 *  Created on: Feb 19, 2013
 *      Author: wkb6223
 */

#include "TimeCalculator.h"
#include "TimeEvent.h"
#include <pthread.h>
#include <unistd.h>

TimeCalculator::TimeCalculator(Dispatcher* dispatch){
	calc = true;
	setDispatcher(dispatch);
	time( &startTime );
}

void TimeCalculator::notify(Event* ev){

}

void TimeCalculator::grabTime(){
	time(&recTime);
}

double TimeCalculator::getCurrentTime(){
	grabTime();
	return difftime(recTime, startTime);
}

Event* TimeCalculator::getTime(){
	int seconds = getCurrentTime();
	int minutes = seconds/60;
	seconds = seconds%60;
	TimeEvent* timeEvent = new TimeEvent();
	timeEvent->setMinutes(minutes);
	timeEvent->setSeconds(seconds);
	return timeEvent;
}

void* checkTime(void* clock){
	TimeCalculator* tc = ((TimeCalculator*)clock);
	while (true){
		tc->trigger(tc->getTime());
		usleep(1000000);
	}
	return NULL;
}

void TimeCalculator::startClock(){
	pthread_t time_t;
	pthread_create(&time_t, NULL, checkTime, this);
}
