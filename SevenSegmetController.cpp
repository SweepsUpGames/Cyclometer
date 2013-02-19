/*
 * SevenSegmetController.cpp
 *
 *  Created on: Feb 12, 2013
 *      Author: wkb6223
 */

#include "SevenSegmetController.h"
#include <iostream>
#include <unistd.h>
#include <hw/inout.h>
#include <sys/mman.h>
#include <sys/neutrino.h>

using namespace std;

SevenSegmetController::SevenSegmetController() {
	if ( ThreadCtl(_NTO_TCTL_IO, NULL) == -1) {
		perror("Failed to get I/O access permission");
	}

	ctrlHandle = mmap_device_io(IO_PORT_SIZE, CTRL_ADDRESS);
	if(ctrlHandle == MAP_DEVICE_FAILED){
		perror("Failed to map control register");
	}

	int result = pthread_mutex_init(&sevenSegmetMutex, NULL);
	if (result != 0){
		printf("Mutex error: %d\n", result);
	}

	out8((ctrlHandle + DIGITAL_REG), INIT_CTRL_REG);

	anode0 = new Anode(ANODE0, -1, false);
	anode1 = new Anode(ANODE1, -1, false);
	anode2 = new Anode(ANODE2, -1, false);
	anode3 = new Anode(ANODE3, -1, false);
	running = true;

}

void SevenSegmetController::notify ( Event* event ){
	sscQueue.push_back(event);
}

void SevenSegmetController::setDispather(Dispatcher *dispatch){
	dispatcher = dispatch;
	dispatcher->subscribe(ev::DISPLAY, this);
}

void SevenSegmetController::setDisplay(double current, double average){
	bool decimalFirst = false;
	bool decimalSecond = false;
	if (current < 10){
		decimalFirst = true;
	}
	if (average < 10){
		decimalSecond = true;
	}

	anode3->setVal(getFirstDiget(current), decimalFirst );
	anode2->setVal(getSecondDiget(current), false );
	anode1->setVal(getFirstDiget(average), decimalSecond );
	anode0->setVal(getSecondDiget(average), false );
}

void SevenSegmetController::setDisplay(int number, bool leadingZeros ){
	if(number >= 1000){
		anode3->setVal(number/1000);
	} else if ( leadingZeros ) {
		anode3->setVal(0);
	} else {
		anode3->setVal(-1);
	}
	if(number >= 100){
		anode2->setVal((number/100)%10);
	} else if ( leadingZeros ) {
		anode2->setVal(0);
	} else {
		anode2->setVal(-1);
	}
	if(number >= 10){
		anode1->setVal((number/10)%10);
	} else if ( leadingZeros ) {
		anode1->setVal(0);
	} else {
		anode1->setVal(-1);
	}
	if(number >= 1){
		anode0->setVal((number)%10);
	} else if ( leadingZeros ) {
		anode0->setVal(0);
	} else {
		anode0->setVal(-1);
	}
}

void SevenSegmetController::setDisplay(double number){
	if (number > 999.9){
		anode3->setVal(9);
		anode2->setVal(9);
		anode1->setVal(9, true);
		anode0->setVal(9);
	} else if (number > 99.9){
		int intNum = number;
		anode3->setVal(intNum/100);
		anode2->setVal((intNum/10)%10);
		anode1->setVal(intNum%10, true);
		anode0->setVal((number - intNum)*10);
	} else if (number > 9.9){
		int intNum = number;
		anode3->setVal(0);
		anode2->setVal(intNum/10);
		anode1->setVal(intNum%10, true);
		anode0->setVal((number - intNum)*10);
	} else if (number > 0.9){
		int intNum = number;
		anode3->setVal(0);
		anode2->setVal(0);
		anode1->setVal(intNum, true);
		anode0->setVal((number - intNum)*10);
	} else if (number > 0.0){
		anode3->setVal(0);
		anode2->setVal(0);
		anode1->setVal(0, true);
		anode0->setVal(number*10);
	} else {
		anode3->setVal(0);
		anode2->setVal(0);
		anode1->setVal(0, true);
		anode0->setVal(0);
	}
}

int SevenSegmetController::getFirstDiget(double number){
	int ret = 0;
	if(number < 10)	{
		ret = (int)number;
	}
	else {
		ret = (int)number/10;
	}
	return ret;
}

int SevenSegmetController::getSecondDiget(double number){
	int ret = 0;
	if(number < 10)	{
		while ( number > 1.0 ){
			number = number-1.0;
		}
		ret = (int)(number*10);
	}
	else {
		ret = (int)number%10;
	}
	return ret;
}

void SevenSegmetController::updateDisplay(){
	if (!sscQueue.empty()){
		sscQueue.front()->run(this);
		sscQueue.pop_front();
	}
	anode0->update();
	usleep(5);
	anode1->update();
	usleep(5);
	anode2->update();
	usleep(5);
	anode3->update();
	usleep(5);
}

bool SevenSegmetController::isRunning(){
	return running;
}

void* runDisplay(void* ssc){
	while (((SevenSegmetController *) ssc)->isRunning()){
		((SevenSegmetController *) ssc)->updateDisplay();
	}
	return NULL;
}

void SevenSegmetController::startDisplay(){
	pthread_t ssc_t;
	pthread_create(&ssc_t, NULL, runDisplay, this);
}
