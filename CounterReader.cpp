/*
 * CounterReader.cpp
 *
 *  Created on: Feb 14, 2013
 *      Author: wkb6223
 */

#include "CounterReader.h"
#include "Constants.h"
#include "UpdateDisplayEvent.h"

#include <iostream>
#include <hw/inout.h>
#include <sys/mman.h>
#include <sys/neutrino.h>
#include <unistd.h>

using namespace std;

CounterReader::CounterReader(){
	if ( ThreadCtl(_NTO_TCTL_IO, NULL) == -1) {
			perror("Failed to get I/O access permission");
		}

		ctrlHandle = mmap_device_io(IO_PORT_SIZE, CTRL_ADDRESS);
		if(ctrlHandle == MAP_DEVICE_FAILED){
			perror("Failed to map control register");
		}

		int result = pthread_mutex_init(&counterReaderMutex, NULL);
		if (result != 0){
			printf("Mutex error: %d\n", result);
		}

		out8(BASE4, EXTERNALCLOCK);
		out8(LOW, 0xFF);
		out8(MED, 0xFF);
		out8(GATE_CTRL, INIT_COUNT_CTRL_REG);
		out8(GATE_CTRL, 0xA0);
		usleep(50);
		out8(GATE_CTRL, ENABLE_COUNT);
		usleep(50);
}

CounterReader::~CounterReader(){
	//delete(this);
}

void CounterReader::trigger(Event event){
	dispatch.dispatch(event);
}

void CounterReader::checkCounter(){
	out8(GATE_CTRL, LATCH_ON);
	usleep(50);
	int read = 0x00;
	read = in8(LOW);
	UpdateDisplayEvent ude = UpdateDisplayEvent();
	ude.setAverage(255-read);
	ude.setCurrent(255-read);
	trigger(ude);
	usleep(1000000);
}

void CounterReader::setDispatcher(Dispatcher dispatcher){
	dispatch = dispatcher;
}

void* runCounter(void* cr){
	CounterReader* counter = (CounterReader*)cr;
	for(;;){
		counter->checkCounter();
	}
	return NULL;
}

void CounterReader::startCounter(){
	pthread_t cr_t;
	pthread_create(&cr_t, NULL, runCounter, this);
}
