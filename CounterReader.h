/*
 * CounterReader.h
 *
 *  Created on: Feb 14, 2013
 *      Author: wkb6223
 */

#ifndef COUNTERREADER_H_
#define COUNTERREADER_H_

#include "Generator.h"

#include <pthread.h>
#include <stdint.h>

class CounterReader:public Generator{
private:
	pthread_mutex_t counterReaderMutex;
	uintptr_t ctrlHandle;

public:
	CounterReader();
	~CounterReader();
	void checkCounter();
	void setDispatcher(Dispatcher* dispatcher);
	void trigger(Event* event);
	void startCounter();
};

#endif /* COUNTERREADER_H_ */
