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
	bool modePushed = false;
	bool startPushed = false;
	bool setPushed = false;
	int modeCount = 0;
	int startCount = 0;
	int setCount = 0;

	for (;;){
		uintptr_t rawButtons = self->readButtons();
		uintptr_t buttons = ( rawButtons & 0b00000111);
		if (((buttons & 0b00000001) == 1)){
			if(!modePushed){
				modePushed = true;
				printf("Mode pressed ");
			} else {
				modeCount++;
			}
		} else if ( ((buttons & 0b00000001) == 0) && modePushed ) {
			modePushed = false;
			printf("Mode released: %i ", modeCount);
			modeCount = 0;
		}

		if (((buttons & 0b00000010) == 2)){
			if(!startPushed){
				startPushed = true;
				printf("Start pressed ");
			} else {
				startCount++;
			}
		} else if (((buttons & 0b00000010) == 0) && startPushed){
			startPushed = false;
			printf("Start released: %i ", startCount);
			startCount = 0;
		}

		if (((buttons & 0b00000100) == 4)){
			if(!setPushed){
				setPushed = true;
				printf("Set pressed ");
			} else {
				setCount++;
			}
		} else if (((buttons & 0b00000100) == 0) && setPushed){
			setPushed = false;
			printf("Set released: %i ", setCount);
			setCount = 0;
		}
		printf("\ntick\n");
		usleep(200000);
	}
	return NULL;
}



void ButtonReader::readInput(){
	pthread_t button_t;
	pthread_create(&button_t, NULL, getButtonInput, this);
}
