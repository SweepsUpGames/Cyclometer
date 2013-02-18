/*
 * DisplayStateMachine.cpp
 *
 *  Created on: Feb 18, 2013
 *      Author: wkb6223
 */

#include "DisplayStateMachine.h"

DisplayStateMachine::DisplayStateMachine(Dispatcher* dispatcher){
	StateMachine::setDispatcher(dispatcher);
	sub(ev::MODE, this);
	sub(ev::ADVANCE_DISPLAY, this);
	sus = new SelectUnitsState();
	scss = new SelectCircumferanceSizeState();
	advanceState(sus);
}

void DisplayStateMachine::notify(Event* ev){
	if(ev->getEventType() == ev::ADVANCE_DISPLAY){
		if (curState == sus){
			advanceState(scss);
		}
	} else {
		StateMachine::trigger(curState->giveEvent(ev));
	}
}
