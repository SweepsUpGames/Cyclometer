/*
 * DisanceDisplayState.cpp
 *
 *  Created on: Feb 19, 2013
 *      Author: wkb6223
 */

#include "DisanceDisplayState.h"
#include "UpdateDisplayDistanceEvent.h"
#include "SelectCircumferanceSizeState.h"
#include "UpdateDisplaySMEvent.h"
#include "UpdateDistanceEvent.h"

DisanceDisplayState::DisanceDisplayState(int tireS){
	tire = false;
	tireSize = tireS;
}

State* DisanceDisplayState::getNextState(){
	if (tire){
		return new SelectCircumferanceSizeState(tireSize);
	} else {
		return this;
	}
}

Event* DisanceDisplayState::giveEvent(Event* event){
	if (event->getEventType() == ev::SET){
		UpdateDisplaySMEvent* udsme = new UpdateDisplaySMEvent();
		tire = true;
		return udsme;
	} else if (event->getEventType() == ev::DIST){
		double dist = ((UpdateDistanceEvent*)event)->getDistance();
		UpdateDisplayDistanceEvent* update = new UpdateDisplayDistanceEvent();
		update->setDist(dist);
		return update;
	} else if (event->getEventType() == ev::MODE){
		UpdateDisplaySMEvent* udsme = new UpdateDisplaySMEvent();
		tire = false;
		return udsme;
	}

	return NULL;
}

Event* DisanceDisplayState::onEnter(){
	UpdateDisplayDistanceEvent* update = new UpdateDisplayDistanceEvent();
	update->setDist(0.0);
	return update;
}

Event* DisanceDisplayState::onExit(){
	return NULL;
}

Event* DisanceDisplayState::onExit2(){
	return NULL;
}
