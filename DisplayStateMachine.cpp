/*
 * DisplayStateMachine.cpp
 *
 *  Created on: Feb 18, 2013
 *      Author: wkb6223
 */

#include "DisplayStateMachine.h"

DisplayStateMachine::DisplayStateMachine(Dispatcher* dispatcher){
	StateMachine::setDispatcher(dispatcher);
	first = 0;
	sub(ev::MODE, this);
	sub(ev::SET, this);
	sub(ev::ADVANCE_DISPLAY, this);
	sub(ev::DIST, this);
	sub(ev::SPEED, this);
	sub(ev::TIME, this);
	sus = new SelectUnitsState();
	scss = new SelectCircumferanceSizeState();
	advanceState(sus);
}

void DisplayStateMachine::notify(Event* ev){
	if(ev->getEventType() == ev::ADVANCE_DISPLAY){
		State* next = curState->getNextState();
		StateMachine::advanceState(next);
	} else {
		StateMachine::trigger(curState->giveEvent(ev));
	}
}
