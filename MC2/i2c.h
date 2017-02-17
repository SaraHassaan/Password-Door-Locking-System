/*
 * i2c.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Sara
 */

#ifndef I2C_H_
#define I2C_H_

#include "macro.h"
#include"micro_config.h"
#include"std_types.h"

void i2c_init();
void start_bit_i2c();
void stop_bit_i2c();
void write_i2c(uint8 data);
uint8 read_byte_ack_i2c();
uint8 read_byte_Nack_i2c();
uint8 read_status_i2c();

#endif /* I2C_H_ */
