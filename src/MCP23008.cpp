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

#include <syslog.h>		/* Syslog functionality */
#include "MCP23008.h"

MCP23008::MCP23008(int bus, int address) {
	i2c = new I2CDevice(bus, address);

	//turn off auto incrementing of registers
	i2c->write_byte(IOCON, IOCON_SEQOP);
}

MCP23008::~MCP23008() {
	delete i2c;
}

void MCP23008::enable(uint8_t) {

}
void MCP23008::disable(uint8_t) {

}
void MCP23008::toggle(uint8_t) {

}
void MCP23008::on(void) {

}
void MCP23008::off(void) {

}
uint8_t MCP23008::get(uint8_t) {
	return -1;
}
void MCP23008::set(uint8_t pin, uint8_t state) {

}
void MCP23008::setDir(uint8_t, uint8_t) {

}
uint8_t MCP23008::getDir(uint8_t) {
	return -1;
}
void MCP23008::setAllInput() {

}
void MCP23008::setAllOutput() {

}

