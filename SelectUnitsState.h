/*
 * SelectUnitsState.h
 *
 *  Created on: Feb 18, 2013
 *      Author: wkb6223
 */

#ifndef SELECTUNITSSTATE_H_
#define SELECTUNITSSTATE_H_

#include "State.h"

class SelectUnitsState: public State{
private:
	bool km;

public:
	SelectUnitsState();
	Event* onEnter();
	Event* giveEvent(Event* event);
};

#endif /* SELECTUNITSSTATE_H_ */
