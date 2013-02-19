/*
 * StateMachine.h
 *
 *  Created on: Feb 18, 2013
 *      Author: wkb6223
 */

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

#include "Generator.h"
#include "Receiver.h"
#include "State.h"

class Event;
class StateMachine: public Generator,Receiver{
protected:
	State* curState;
	Dispatcher* dispatcher;
	int first;

public:
	StateMachine();

	void setDispatcher(Dispatcher* dispatch){
		dispatcher = dispatch;
	}

	void sub(ev::EventType evType, StateMachine* receiver){
		dispatcher->subscribe(evType, ((Receiver*)receiver));
	}

	void notify(Event* ev){
		StateMachine::trigger(curState->giveEvent(ev));
	}

	void trigger(Event* event){
		dispatcher->dispatch(event);
	}

	void advanceState(State* newState){
		Event* event;
		if (first != 0){
			event = curState->onExit();
			trigger(event);
			event = curState->onExit2();
			trigger(event);
		} else {
			first = 1;
		}
		curState = newState;
		event = curState->onEnter();
		trigger(event);
	}

};


#endif /* STATEMACHINE_H_ */
