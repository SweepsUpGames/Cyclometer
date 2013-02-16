/*
 * Generator.h
 *
 *  Created on: Feb 14, 2013
 *      Author: wkb6223
 */

#ifndef GENERATOR_H_
#define GENERATOR_H_

class Generator{
public:
	virtual void trigger(Event event);

private:
	Dispatcher dispatch;
};

#endif /* GENERATOR_H_ */
