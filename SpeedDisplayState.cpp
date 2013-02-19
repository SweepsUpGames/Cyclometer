/*
 * SpeedDisplayState.cpp
 *
 *  Created on: Feb 18, 2013
 *      Author: wkb6223
 */

#include "SpeedDisplayState.h"
#include "UpdateSpeedEvent.h"
#include "UpdateDisplayEvent.h"

SpeedDisplayState::SpeedDisplayState(){

}

State* SpeedDisplayState::getNextState(){
	//return NULL;
}

Event* SpeedDisplayState::giveEvent(Event* event){
	if(event->getEventType() == ev::SPEED){
		UpdateDisplayEvent* ude = new UpdateDisplayEvent();
		ude->setAverage(((UpdateSpeedEvent*)event)->getAverage());
		ude->setCurrent(((UpdateSpeedEvent*)event)->getCurrent());
		return ude;
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
