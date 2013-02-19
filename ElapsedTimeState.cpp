/*
 * ElapsedTimeState.cpp
 *
 *  Created on: Feb 19, 2013
 *      Author: wkb6223
 */

#include "ElapsedTimeState.h"
#include "SpeedDisplayState.h"
#include "UpdateDisplaySMEvent.h"
#include "UpdateDisplayNumberEvent.h"
#include "UpdateElapcedTimeEvent.h"
#include "TimeEvent.h"

ElapsedTimeState::ElapsedTimeState(int tire){
	tireSize = tire;
}

Event* ElapsedTimeState::onEnter(){
	UpdateElapcedTimeEvent* update = new UpdateElapcedTimeEvent();
	update->setMinutes(0);
	update->setSeconds(0);
	return update;
}

Event* ElapsedTimeState::onExit(){
	return NULL;
}

Event* ElapsedTimeState::onExit2(){
	return NULL;
}

Event* ElapsedTimeState::giveEvent(Event* event){
	if (event->getEventType() == ev::MODE){
		UpdateDisplaySMEvent* udsme = new UpdateDisplaySMEvent();
		return udsme;
	} else if (event->getEventType() == ev::TIME){
		UpdateElapcedTimeEvent* update = new UpdateElapcedTimeEvent();
		update->setMinutes(((TimeEvent*)event)->getMinutes());
		update->setSeconds(((TimeEvent*)event)->getSeconds());
		return update;
	}
	return NULL;
}

State* ElapsedTimeState::getNextState(){
	return new SpeedDisplayState(tireSize);
}
