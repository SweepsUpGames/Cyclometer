/*
 * State.h
 *
 *  Created on: Feb 18, 2013
 *      Author: wkb6223
 */

#ifndef STATE_H_
#define STATE_H_

//#include "StateMachine.h"
//#include "Event.h"

class Event;
class StateMachine;
class State{
public:
	virtual Event* onEnter()=0;
	virtual Event* onExit()=0;
	virtual Event* onExit2()=0;
	virtual Event* onExit3()=0;
	virtual Event* giveEvent(Event* event)=0;
	virtual State* getNextState()=0;
	void setStateMachine(StateMachine* sm){
		stateMachine = sm;
	}

protected:
	StateMachine* stateMachine;
};

#endif /* STATE_H_ */
