/*
 * DisplayStateMachine.h
 *
 *  Created on: Feb 18, 2013
 *      Author: wkb6223
 */

#ifndef DISPLAYSTATEMACHINE_H_
#define DISPLAYSTATEMACHINE_H_

#include "StateMachine.h"
#include "SelectUnitsState.h"
#include "SelectCircumferanceSizeState.h"

class Dispatcher;
class DisplayStateMachine: public StateMachine{
public:
	DisplayStateMachine(Dispatcher* dispatcher);
	void notify(Event* ev);

protected:
	SelectUnitsState* sus;
	SelectCircumferanceSizeState* scss;
};


#endif /* DISPLAYSTATEMACHINE_H_ */
