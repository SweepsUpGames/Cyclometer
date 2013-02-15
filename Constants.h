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
#define INIT_CTRL_REG 0b00000010

// Initializes value for the counter control register
#define INIT_COUNT_CTRL_REG 0b00000010
#define ENABLE_GATE0 0b00010000
#define ENABLE_COUNT 0b00000100
#define LATCH_ON 0b01000000
#define LATCH_OFF 0b00000000

// Address of the digital register
#define DIGITAL_REG 0x0B

// offset from the base address for:
#define DIO_A CTRL_ADDRESS + 0x08 // DIO_A
#define DIO_B CTRL_ADDRESS + 0x09 // DIO_B
#define DIO_C CTRL_ADDRESS + 0x0A // DIO_C
#define GATE_CTRL CTRL_ADDRESS + 0x0F //gate control register
#define LSB CTRL_ADDRESS + 0x0C //least significant byte

#endif /* CONSTANTS_H_ */
