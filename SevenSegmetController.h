/*
 * SevenSegmetController.h
 *
 *  Created on: Feb 12, 2013
 *      Author: wkb6223
 */

#ifndef SEVENSEGMETCONTROLLER_H_
#define SEVENSEGMETCONTROLLER_H_

#include "CyclometerReceiver.h"
#include "Anode.h"
#include "Display.h"
#include "Constants.h"

#include <pthread.h>
#include <stdint.h>
#include <list>


class SevenSegmetController: public CyclometerReceiver {
private:
	pthread_mutex_t sevenSegmetMutex;
	uintptr_t ctrlHandle;
	Anode* anode0;
	Anode* anode1;
	Anode* anode2;
	Anode* anode3;
	bool running;
	std::list<Event*> sscQueue;
	int getFirstDiget(double number);
	int getSecondDiget(double number);

public:
	SevenSegmetController();
	void setDisplay(int number, bool leadingZeros );
	void setDisplay(double current, double average);
	void handleEvent ( Event* event );
	bool isRunning();
	void updateDisplay();
	void startDisplay();
};

#endif /* SEVENSEGMETCONTROLLER_H_ */
