/*
 * CalcStateMachine.cpp
 *
 *  Created on: Feb 19, 2013
 *      Author: wkb6223
 */

#include "CalcStateMachine.h"
#include "ManualOffState.h"


CalcStateMachine::CalcStateMachine(Dispatcher* dispatcher){
	StateMachine::setDispatcher(dispatcher);
	sub(ev::AUTO, this);
	StateMachine::advanceState(new ManualOffState());
}

void CalcStateMachine::notify(Event* ev){
	if(ev->getEventType() == ev::AUTO){
		State* next = curState->getNextState();
		printf("nextState\n");
		StateMachine::advanceState(next);
	}
}
