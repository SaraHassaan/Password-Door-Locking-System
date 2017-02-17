/*
 * door.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Sara
 */

#ifndef DOOR_H_
#define DOOR_H_

#include"macro.h"
#include"micro_config.h"
#include"std_types.h"

void change_password();
void key_pressed(uint8 *str_written);
uint8 password_first_time();

#endif /* DOOR_H_ */
