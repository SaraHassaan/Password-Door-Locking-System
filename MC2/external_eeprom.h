/*
 * external_eeprom.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Sara
 */

#ifndef EXTERNAL_EEPROM_H_
#define EXTERNAL_EEPROM_H_

#include "macro.h"
#include"micro_config.h"
#include"std_types.h"
#include"i2c.h"


uint8 write_eeprom(uint16 address,uint8 data);
uint8 read_eeprom(uint16 address,uint8 *ptr_data);

#endif /* EXTERNAL_EEPROM_H_ */
