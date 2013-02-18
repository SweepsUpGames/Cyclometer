/*
 * ButtonReader.h
 *
 *  Created on: Feb 17, 2013
 *      Author: wkb6223
 */

#ifndef BUTTONREADER_H_
#define BUTTONREADER_H_

#include "Generator.h"
#include <stdint.h>
#include <list>

using namespace std;

class ButtonReader: public Generator{
private:
	uintptr_t ctrlHandle;
	int curValues;
	list<uintptr_t>* values;

public:
	ButtonReader();
	~ButtonReader();
	list<uintptr_t>* getCurrentValues();
	uintptr_t readButtons();
	void readInput();
	void trigger(Event* event);

};

#endif /* BUTTONREADER_H_ */
