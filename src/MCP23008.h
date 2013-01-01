/*
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 * Name        : MCP23008.h
 * Author      : Georgi Todorov
 * Version     :
 * Created on  : Jan 1, 2013
 *
 * Copyright © 2012 Georgi Todorov  <terahz@geodar.com>
 */

#ifndef MCP23008_H_
#define MCP23008_H_
#include <inttypes.h>
#include "I2CDevice.h"

// Register Definitions
#define IODIR	0x00
#define IPOL	0x01
#define GPINTEN	0x02
#define DEFVAL	0x03
#define INTCON	0x04
#define IOCON	0x05
#define GPPU	0x06
#define INTF	0x07
#define INTCAP	0x08
#define GPIO	0x09
#define OLAT	0x0A

#define IOCON_INTPOL	0x02 //1 - Active-high; 0 - Active low;
#define IOCON_ODR		0x04 //1 - Open-driven (overrides INTPOL); 0 - Active driver (INTPOL sets polarity)
#define IOCON_DISSLW	0x10 //1 - Slew rate disabled; 0 - Slew rate enabled
#define IOCON_SEQOP		0x20 //1 - Address pointer does not increment;0 - Address pointer increments
#define IO_INPUT	0;
#define IO_OUTPUT	1;

class MCP23008 {
public:
	MCP23008(int, int);
	virtual ~MCP23008();
	void enable(uint8_t);
	void disable(uint8_t);
	void toggle(uint8_t);
	void set(uint8_t, uint8_t);
	void on(void);
	void off(void);
	uint8_t get(uint8_t);
	void setDir(uint8_t, uint8_t);
	uint8_t getDir(uint8_t);
	void setAllInput();
	void setAllOutput();

private:
	I2CDevice *i2c;

};

#endif /* MCP23008_H_ */
