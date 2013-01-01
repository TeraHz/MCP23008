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
 * Name        : MCP23008.cpp
 * Author      : Georgi Todorov
 * Version     :
 * Created on  : Jan 1, 2013
 *
 * Copyright © 2012 Georgi Todorov  <terahz@geodar.com>
 */

#include "MCP23008.h"

MCP23008::MCP23008(int bus, int address) {
	i2c = new I2CDevice(bus, address);
}

MCP23008::~MCP23008() {
	delete i2c;
}

void MCP23008::set(uint8_t pin, uint8_t state){

}

uint8_t MCP23008::get(uint8_t pin){
	return -1;
}
