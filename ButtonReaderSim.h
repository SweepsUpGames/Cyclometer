/*
 * ButtonReader.h
 *
 *  Created on: Feb 15, 2013

 *      Author: ajm6611
>>>>>>> Implemented generator, receiver and dispatcher
 */

#ifndef BUTTONREADER_H_
#define BUTTONREADER_H_


#include "Generator.h"
#include <stdint.h>
#include <list>


class ButtonReaderSim: public Generator{
private:
	uintptr_t ctrlHandle;
	uintptr_t curValues;
	std::list<uintptr_t>* values;
	//Dispatcher dispatcher;


public :
	ButtonReaderSim();
	~ButtonReaderSim();
	void readInput();
	uintptr_t readButtons();
	void readButton();
	std::list<uintptr_t>* getCurrentValues();
	void start();
	void trigger(Event ev);

};

#endif /* BUTTONREADER_H_ */
