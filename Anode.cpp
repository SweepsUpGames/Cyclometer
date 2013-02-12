/*
 * Anode.cpp
 *
 *  Created on: Feb 12, 2013
 *      Author: wkb6223
 */

#include <hw/inout.h>
#include <iostream>

#include "Anode.h"
#include "Display.h"
#include "Constants.h"

using namespace std;

Anode::Anode( uintptr_t openPort, double startVal ){
	setPort( openPort );
	setVal( startVal );
}

void Anode::update(){
	//sends out signals saying change the port to the value
	out8(DIO_C, port);
	out8(DIO_A, val);
}

void Anode::setVal( double newVal ){
	if ( newVal == 1 )
		val = LITE_1;
	if ( newVal == 2 )
		val = LITE_2;
	if ( newVal == 3 )
		val = LITE_3;
	if ( newVal == 4 )
		val = LITE_4;
	if ( newVal == 5 )
		val = LITE_5;
	if ( newVal == 6 )
		val = LITE_6;
	if ( newVal == 7 )
		val = LITE_7;
	if ( newVal == 8 )
		val = LITE_8;
	if ( newVal == 9 )
		val = LITE_9;
	if ( newVal == 0 )
		val = LITE_0;
	if ( newVal == .1 )
		val = LITE_1 ^ LITE_POINT;
	if ( newVal == .2 )
		val = LITE_2 ^ LITE_POINT;
	if ( newVal == .3 )
		val = LITE_3 ^ LITE_POINT;
	if ( newVal == .4 )
		val = LITE_4 ^ LITE_POINT;
	if ( newVal == .5 )
		val = LITE_5 ^ LITE_POINT;
	if ( newVal == .6 )
		val = LITE_6 ^ LITE_POINT;
	if ( newVal == .7 )
		val = LITE_7 ^ LITE_POINT;
	if ( newVal == .8 )
		val = LITE_8 ^ LITE_POINT;
	if ( newVal == .9 )
		val = LITE_9 ^ LITE_POINT;

}

void Anode::setPort( uintptr_t newPort ){
	port = newPort;
}
