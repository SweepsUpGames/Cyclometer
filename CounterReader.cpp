/*
 * CounterReader.cpp
 *
 *  Created on: Feb 14, 2013
 *      Author: wkb6223
 */

#include "CounterReader.h"
#include "Constants.h"

#include <iostream>
#include <hw/inout.h>
#include <sys/mman.h>
#include <sys/neutrino.h>

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

		out8(GATE_CTRL, INIT_COUNT_CTRL_REG);
		out8(GATE_CTRL, ENABLE_GATE0);
		out8(GATE_CTRL, ENABLE_COUNT);

}

CounterReader::~CounterReader(){
	//delete(this);
}

uint8_t CounterReader::checkCounter(){
	//TODO reset counter
	out8(GATE_CTRL, LATCH_ON);
	uint8_t read = 0x00;
	read = in8(LSB);

	return read;
}

