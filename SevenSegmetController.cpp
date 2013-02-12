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

	anode0 = new Anode( ANODE0, (int)0 );
	anode1 = new Anode( ANODE1, .1 );
	anode2 = new Anode( ANODE2, 2 );
	anode3 = new Anode( ANODE3, 3 );

}

void SevenSegmetController::giveEvent(Event e){

}

void SevenSegmetController::runDisplay(){
	while (true){
		anode0->update();
		usleep(5);
		anode1->update();
		usleep(5);
		anode2->update();
		usleep(5);
		anode3->update();
		usleep(5);
	}
}
