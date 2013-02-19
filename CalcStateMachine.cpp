/*
 * CalcStateMachine.cpp
 *
 *  Created on: Feb 19, 2013
 *      Author: wkb6223
 */

#include "CalcStateMachine.h"

CalcStateMachine::CalcStateMachine(Dispatcher* dispatcher){
	StateMachine::setDispatcher(dispatcher);
}

void CalcStateMachine::notify(Event* ev){
	if(ev->getEventType() == ev::AUTO){

	}
}
