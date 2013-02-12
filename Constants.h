/*
 * Constants.h
 *
 *  Created on: Feb 12, 2013
 *      Author: wkb6223
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

// Port size for insializing
#define IO_PORT_SIZE 1

// base address for mapping registers
#define CTRL_ADDRESS 0x280

// Initialization value for the control register
#define INIT_CTRL_REG 0x83 //1XX00X11 // 131

// Address of the digitial register
#define DIGITAL_REG 0x0B

// offset from the base address for:
#define DIO_A CTRL_ADDRESS + 0x08 // DIO_A
#define DIO_B CTRL_ADDRESS + 0x09 // DIO_B
#define DIO_C CTRL_ADDRESS + 0x0A // DIO_C

#endif /* CONSTANTS_H_ */
