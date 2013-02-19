/*
 * SelectCircumferanceSizeState.cpp
 *
 *  Created on: Feb 18, 2013
 *      Author: wkb6223
 */

#include "SelectCircumferanceSizeState.h"
#include "SpeedDisplayState.h"
#include "UpdateDisplayNumberEvent.h"
#include "UpdateDisplaySMEvent.h"
#include "TireSizeEvent.h"
#include "DisanceDisplayState.h"

SelectCircumferanceSizeState::SelectCircumferanceSizeState(){
	outside = false;
	tireSize = 210;
}

SelectCircumferanceSizeState::SelectCircumferanceSizeState(int tire){
	tireSize = tire;
	outside = true;
}

Event* SelectCircumferanceSizeState::onEnter(){
	UpdateDisplayNumberEvent* update = new UpdateDisplayNumberEvent();
	update->setNumber(tireSize);
	update->setLeadingZeros(false);
	return update;
}

Event* SelectCircumferanceSizeState::giveEvent(Event* event){
	if (event->getEventType() == ev::MODE){
		tireSize = (tireSize + 1);
		if(tireSize > 220){
			tireSize = 190;
		}
		UpdateDisplayNumberEvent* update = new UpdateDisplayNumberEvent();
		update->setNumber(tireSize);
		update->setLeadingZeros(false);
		return update;
	} else if (event->getEventType() == ev::SET){
		UpdateDisplaySMEvent* udsme = new UpdateDisplaySMEvent();
		return udsme;
	}
	return NULL;
}

Event* SelectCircumferanceSizeState::onExit(){
	TireSizeEvent* tire = new TireSizeEvent();
	tire->setTireSize(tireSize);
	return tire;
}

Event* SelectCircumferanceSizeState::onExit2(){
	TireSizeEvent* tire = new TireSizeEvent();
	tire->setTireSize(tireSize);
	tire->setType(ev::TIRE_SIZE2);
	return tire;
}

State* SelectCircumferanceSizeState::getNextState(){
	if (outside){
		return new DisanceDisplayState(tireSize);
	} else {
		return new SpeedDisplayState(tireSize);
	}
}
