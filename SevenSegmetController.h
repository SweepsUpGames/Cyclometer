/*
 * SevenSegmetController.h
 *
 *  Created on: Feb 12, 2013
 *      Author: wkb6223
 */

#ifndef SEVENSEGMETCONTROLLER_H_
#define SEVENSEGMETCONTROLLER_H_

#include "Anode.h"
#include "Display.h"
#include "Constants.h"
#include "Event.h"

#include <pthread.h>
#include <stdint.h>

class SevenSegmetController {
private:
	pthread_mutex_t sevenSegmetMutex;
	uintptr_t ctrlHandle;
	Anode* anode0;
	Anode* anode1;
	Anode* anode2;
	Anode* anode3;

public:
	SevenSegmetController();
	void giveEvent(Event e);
	void runDisplay();

};

#endif /* SEVENSEGMETCONTROLLER_H_ */
