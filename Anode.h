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
	uint8_t port;
	uint8_t val;
public:
	Anode( uint8_t port, int val, bool decimal );
	void update();
	void setVal( int val );
	void setVal( int val, bool decimal );
	void setPort( uint8_t port );
};

#endif /* ANODE_H_ */
