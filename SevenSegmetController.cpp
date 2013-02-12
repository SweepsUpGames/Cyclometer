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

}

void SevenSegmetController::giveEvent(Event e){

}

void SevenSegmetController::runDisplay(){
	while (true){
		printf("Ran once\n");
		out8((ctrlHandle + DIO_C), 0b01111111);
		out8((ctrlHandle + DIO_A), LITE_POINT);
		usleep(5);
		out8((ctrlHandle + DIO_C), 0b10111111);
		out8((ctrlHandle + DIO_A), LITE_BLANK);
		usleep(5);
		out8((ctrlHandle + DIO_C), 0b11011111);
		out8((ctrlHandle + DIO_A), LITE_0);
		usleep(5);
		out8((ctrlHandle + DIO_C), 0b11101111);
		out8((ctrlHandle + DIO_A), LITE_6);
		usleep(5);
	}
}
