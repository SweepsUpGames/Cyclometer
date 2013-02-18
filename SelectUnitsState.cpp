/*
 * SelectUnitsState.cpp
 *
 *  Created on: Feb 18, 2013
 *      Author: wkb6223
 */

#include "SelectUnitsState.h"
#include "UpdateDisplayNumberEvent.h"
#include "UpdateDisplaySMEvent.h"

SelectUnitsState::SelectUnitsState(){
	km = true;
}

Event* SelectUnitsState::onEnter(){
	UpdateDisplayNumberEvent* update = new UpdateDisplayNumberEvent();
	update->setNumber(1);
	update->setLeadingZeros(false);
	return update;
}

Event* SelectUnitsState::giveEvent(Event* event){
	if (event->getEventType() == ev::MODE){
		printf("event given\n");
		UpdateDisplayNumberEvent* update = new UpdateDisplayNumberEvent();
		if (km){
			km = false;
			update->setNumber(2);
			update->setLeadingZeros(false);
		} else {
			km = true;
			update->setNumber(1);
			update->setLeadingZeros(false);
		}
		return update;
	} else if (event->getEventType() == ev::SET){
		UpdateDisplaySMEvent* udsme = new UpdateDisplaySMEvent();
		return udsme;
	}
	return NULL;
}
