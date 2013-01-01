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
	i2c = new I2C(bus, address);
	//turn off auto incrementing of registers
	i2c->write_byte(IOCON, IOCON_SEQOP);
	//get current chip state
	ledstate = getState();
}

MCP23008::~MCP23008() {
	delete i2c;
}

void MCP23008::disable(uint8_t n) {
	ledstate = getState();
	ledstate &= ~(1 << (n-1));
	i2c->write_byte(GPIO, ledstate);
}
void MCP23008::enable(uint8_t n) {
	ledstate = getState();
	ledstate |= (1 << (n-1));
	i2c->write_byte(GPIO, ledstate);
}
void MCP23008::toggle(uint8_t n) {
	ledstate = getState();
	ledstate ^= (1 << (n-1));
	i2c->write_byte(GPIO, ledstate);
}
void MCP23008::on(void) {
	ledstate = getState();
	ledstate = 0xff;
	i2c->write_byte(GPIO, ledstate);
}
void MCP23008::off(void) {
	ledstate = getState();
	ledstate = 0x00;
	i2c->write_byte(GPIO, ledstate);

}
uint8_t MCP23008::get(uint8_t n) {
	ledstate = getState();
	syslog(LOG_DEBUG, "LED State: %d", ledstate);
	syslog(LOG_DEBUG, "returning %d", (ledstate & (1<< (n-1)))>>(n-1));
	return ((ledstate & (1<< (n-1)))>>(n-1));
}
void MCP23008::set(uint8_t pin, uint8_t state) {
	syslog(LOG_DEBUG, "Setting pin %d to ", pin);
	switch (state){
	case 1:
		syslog(LOG_DEBUG, "On");
		enable(pin);
		break;
	case 0:
		syslog(LOG_DEBUG, "Off");
		disable(pin);
		break;
	default:
		syslog(LOG_DEBUG, "????");
		//no idea what to do here?
		break;
	}
}
void MCP23008::setDir(uint8_t, uint8_t) {

}
uint8_t MCP23008::getDir(uint8_t) {
	return -1;
}
void MCP23008::setAllInput() {
	i2c->write_byte(IODIR, 0xff);
}
void MCP23008::setAllOutput() {
	i2c->write_byte(IODIR, 0x00);

}

uint8_t MCP23008::getState() {
	return i2c->read_byte(GPIO);
}

