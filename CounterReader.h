/*
 * CounterReader.h
 *
 *  Created on: Feb 14, 2013
 *      Author: wkb6223
 */

#ifndef COUNTERREADER_H_
#define COUNTERREADER_H_

#include <pthread.h>
#include <stdint.h>

class CounterReader{
private:
	pthread_mutex_t counterReaderMutex;
	uintptr_t ctrlHandle;

public:
	CounterReader();
	~CounterReader();
	uint8_t checkCounter();
};

#endif /* COUNTERREADER_H_ */
