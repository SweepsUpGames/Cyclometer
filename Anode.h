/*
 * Anode.h
 *
 *  Created on: Feb 12, 2013
 *      Author: wkb6223
 */

#ifndef ANODE_H_
#define ANODE_H_

#include <stdint.h>
#include "Event.h"

class Anode{
private:
	uintptr_t port;
	uint8_t val;
public:
	Anode( uintptr_t port, double val );
	void update();
	void setVal( double val );
	void setPort( uintptr_t port );
};

#endif /* ANODE_H_ */
