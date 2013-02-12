/*
 * SevenSegmetController.h
 *
 *  Created on: Feb 12, 2013
 *      Author: wkb6223
 */

#ifndef SEVENSEGMETCONTROLLER_H_
#define SEVENSEGMETCONTROLLER_H_

// Port size for insializing
#define IO_PORT_SIZE 1

// base address for mapping registers
#define CTRL_ADDRESS 0x280

// Initialization value for the control register
#define INIT_CTRL_REG 0x83 //1XX00X11 // 131

// Address of the digitial register
#define DIGITAL_REG 0x0B

// offset from the base address for:
#define DIO_A 0x08 // DIO_A
#define DIO_B 0x09 // DIO_B
#define DIO_C 0x0A // DIO_C

// definitions for LED ints
#define LITE_1 0b10011111
#define LITE_2 0b00100101
#define LITE_3 0b00001101
#define LITE_4 0b10011001
#define LITE_5 0b01001001
#define LITE_6 0b01000001
#define LITE_7 0b00011111
#define LITE_8 0b00000001
#define LITE_9 0b00001001
#define LITE_0 0b00000011
#define LITE_POINT 0b11111110
#define LITE_BLANK 0b11111111

#include "Event.h"
#include <pthread.h>
#include <stdint.h>

class SevenSegmetController {
private:
	pthread_mutex_t sevenSegmetMutex;
	uintptr_t ctrlHandle;

public:
	SevenSegmetController();
	void giveEvent(Event e);
	void runDisplay();

};

#endif /* SEVENSEGMETCONTROLLER_H_ */
