/*
 * keypad.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Sara
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include"macro.h"
#include"micro_config.h"
#include"std_types.h"

#define N_col 4
#define N_row 4

#define KEY_PORT_DIR  DDRA
#define KEY_PORT_IN   PINA
#define KEY_PORT_OUT  PORTA


uint8 keypad_getPressedKey();
uint8 Keypad_4x3_adjustSwitchNumber(uint8 num);
uint8 Keypad_4x4_adjustSwitchNumber(uint8 num);


#endif /* KEYPAD_H_ */
