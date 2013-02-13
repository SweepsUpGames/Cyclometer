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

Anode::Anode( uint8_t openPort, int startVal, bool decimal ){
	setPort( openPort );
	setVal( startVal, decimal );
}

void Anode::update(){
	//sends out signals saying change the port to the value
	out8(DIO_C, port);
	out8(DIO_A, val);
}

void Anode::setVal( int newVal ){
	setVal( newVal, false );
}

void Anode::setVal( int newVal, bool decimal ){
	switch(newVal){
	case -1:
		val = LITE_BLANK;
		break;
	case 1:
		val = LITE_1;
		break;
	case 2:
		val = LITE_2;
		break;
	case 3:
		val = LITE_3;
		break;
	case 4:
		val = LITE_4;
		break;
	case 5:
		val = LITE_5;
		break;
	case 6:
		val = LITE_6;
		break;
	case 7:
		val = LITE_7;
		break;
	case 8:
		val = LITE_8;
		break;
	case 9:
		val = LITE_9;
		break;
	case 0:
		val = LITE_0;
		break;
	}
	if ( decimal ){
		val = val - LITE_ADD_POINT;
	}
}

void Anode::setPort( uint8_t newPort ){
	port = newPort;
}
