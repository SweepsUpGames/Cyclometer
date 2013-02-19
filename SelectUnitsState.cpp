/*
 * SelectUnitsState.cpp
 *
 *  Created on: Feb 18, 2013
 *      Author: wkb6223
 */

#include "SelectUnitsState.h"
#include "SelectCircumferanceSizeState.h"
#include "UpdateDisplayNumberEvent.h"
#include "UpdateDisplaySMEvent.h"
#include "SetKilometerEvent.h"

SelectUnitsState::SelectUnitsState(){
	km = true;
}

Event* SelectUnitsState::onEnter(){
	UpdateDisplayNumberEvent* update = new UpdateDisplayNumberEvent();
	update->setNumber(1);
	update->setLeadingZeros(false);
	return update;
}

Event* SelectUnitsState::onExit(){
	SetKilometerEvent* event = new SetKilometerEvent();
	event->setKilometers(km);
	return event;
}

Event* SelectUnitsState::onExit2(){
	SetKilometerEvent* event = new SetKilometerEvent();
	event->setKilometers(km);
	event->setType(ev::KILO2);
	return event;
}

Event* SelectUnitsState::onExit3(){
	return NULL;
}

Event* SelectUnitsState::giveEvent(Event* event){
	if (event->getEventType() == ev::MODE){
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

State* SelectUnitsState::getNextState(){
	return new SelectCircumferanceSizeState();
}
