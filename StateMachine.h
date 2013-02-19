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
#include "CalcOnEvent.h"
#include "CalcOffEvent.h"
#include "ManualOffState.h"
#include "ManualOnState.h"

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
		/*if (event->getEventType() == ev::CALC_ON){
			event = ((CalcOnEvent*)curState)->ManualOnState::onEnter2();
			trigger(event);
			event = ((CalcOnEvent*)curState)->ManualOnState::onEnter3();
			trigger(event);
		} else if (event->getEventType() == ev::CALC_OFF){
			event = ((CalcOffEvent*)curState)->ManualOffState::onEnter2();
			trigger(event);
			event = ((CalcOffEvent*)curState)->ManualOffState::onEnter3();
			trigger(event);
		}*/
	}

};


#endif /* STATEMACHINE_H_ */
