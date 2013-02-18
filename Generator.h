/*
 * Generator.h
 *
 *  Created on: Feb 14, 2013
 *      Author: wkb6223
 */

#ifndef GENERATOR_H_
#define GENERATOR_H_

#include "Event.h"
#include "Dispatcher.h"

class Generator{
public:
	virtual void trigger(Event* event);

protected:
	Dispatcher* dispatch;
};

#endif /* GENERATOR_H_ */
