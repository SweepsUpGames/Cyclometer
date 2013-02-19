/*
 * SpeedDisplayState.cpp
 *
 *  Created on: Feb 18, 2013
 *      Author: wkb6223
 */

#include "SpeedDisplayState.h"
#include "UpdateSpeedEvent.h"
#include "UpdateDisplayEvent.h"
#include "DisanceDisplayState.h"
#include "UpdateDisplaySMEvent.h"

SpeedDisplayState::SpeedDisplayState(int tire){
	tireSize = tire;
}

State* SpeedDisplayState::getNextState(){
	return new DisanceDisplayState(tireSize);
}

Event* SpeedDisplayState::giveEvent(Event* event){
	if(event->getEventType() == ev::SPEED){
		UpdateDisplayEvent* ude = new UpdateDisplayEvent();
		ude->setAverage(((UpdateSpeedEvent*)event)->getAverage());
		ude->setCurrent(((UpdateSpeedEvent*)event)->getCurrent());
		return ude;
	} else if (event->getEventType() == ev::MODE){
		UpdateDisplaySMEvent* udsme = new UpdateDisplaySMEvent();
		return udsme;
	}
	return NULL;
}

Event* SpeedDisplayState::onEnter(){
	UpdateDisplayEvent* ude = new UpdateDisplayEvent();
	ude->setAverage(0.0);
	ude->setCurrent(0.0);
	return ude;
}

Event* SpeedDisplayState::onExit(){
	return NULL;
}

Event* SpeedDisplayState::onExit2(){
	return NULL;
}

Event* SpeedDisplayState::onExit3(){
	return NULL;
}
