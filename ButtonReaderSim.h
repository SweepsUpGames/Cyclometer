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


class ButtonReader: public Generator{
private:
	uintptr_t ctrlHandle;
	uintptr_t curValues;
	std::list<uintptr_t>* values;


public :
	ButtonReader();
	~ButtonReader();
	void readInput();
	uintptr_t readButtons();
	std::list<uintptr_t>* getCurrentValues();
	void start();

};

#endif /* BUTTONREADER_H_ */
