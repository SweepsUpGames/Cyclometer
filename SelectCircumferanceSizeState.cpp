/*
 * SelectCircumferanceSizeState.cpp
 *
 *  Created on: Feb 18, 2013
 *      Author: wkb6223
 */

#include "SelectCircumferanceSizeState.h"
#include "UpdateDisplayNumberEvent.h"

SelectCircumferanceSizeState::SelectCircumferanceSizeState(){
	tireSize = 190;
}

Event* SelectCircumferanceSizeState::onEnter(){
	UpdateDisplayNumberEvent* update = new UpdateDisplayNumberEvent();
	update->setNumber(tireSize);
	update->setLeadingZeros(false);
	return update;
}

Event* SelectCircumferanceSizeState::giveEvent(Event* event){
	if (event->getEventType() == ev::MODE){
		tireSize = (tireSize + 1)%221;
		UpdateDisplayNumberEvent* update = new UpdateDisplayNumberEvent();
		update->setNumber(tireSize);
		update->setLeadingZeros(false);
		return update;
	}
}
