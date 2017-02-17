/*
 * password.h
 *
 *  Created on: ??�/??�/????
 *      Author: Sara
 */

#ifndef PASSWORD_H_
#define PASSWORD_H_

#include "macro.h"
#include"micro_config.h"
#include"std_types.h"
#include"external_eeprom.h"

#define F 0
#define T 1

uint8 check_pass(uint8*recv,uint8*eeprom);
void read_password(uint16 address,uint8 *pass);
void write_pass(uint16 address,uint8 *pass);
uint8 password_first_time();
void change_password_mc2();
uint8 Open_Door_Mc2();

#endif /* PASSWORD_H_ */
