/*
 * ButtonReader.cpp
 *
 *  Created on: Feb 15, 2013
 *      Author: wkb6223
 */

#include "ButtonReader.h"
#include "Constants.h"

#include <iostream>
#include <hw/inout.h>
#include <sys/mman.h>
#include <sys/neutrino.h>
#include <pthread.h>
#include <unistd.h>

using namespace std;

ButtonReader::ButtonReader(){
	if ( ThreadCtl(_NTO_TCTL_IO, NULL) == -1) {
		perror("Failed to get I/O access permission");
	}

	ctrlHandle = mmap_device_io(IO_PORT_SIZE, CTRL_ADDRESS);
	if(ctrlHandle == MAP_DEVICE_FAILED){
		perror("Failed to map control register");
	}
	curValues = in8(DIO_B);
	values = new list<uintptr_t>();

}

ButtonReader::~ButtonReader(){

}

list<uintptr_t>* ButtonReader::getCurrentValues(){
	return values;
}


uintptr_t ButtonReader::readButtons(){
	uintptr_t newValue = in8(DIO_B);
	values->push_back(newValue);
	values->pop_front();
	return newValue;
}

void* getButtonInput(void* obj){
	ButtonReader *self = (ButtonReader* )obj;
	for (;;){
		uintptr_t buttons = (self->readButtons() & 0b00000111);
		printf("here: %i\n", buttons);
		usleep(1000000);
	}
}



void ButtonReader::readInput(){
	pthread_t button_t;
	pthread_create(&button_t, NULL, getButtonInput, this);
}
