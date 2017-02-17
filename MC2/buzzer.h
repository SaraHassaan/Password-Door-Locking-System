/*
 * buzzer.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Sara
 */

#ifndef BUZZER_H_
#define BUZZER_H_


#include "macro.h"
#include"micro_config.h"
#include"std_types.h"

void Init_Alarm();
void Alarm_On();
void Alarm_Off();

#define DDIR_ALARM DDRD
#define PORT_ALARM PORTD

#define B1 PD2

#endif /* BUZZER_H_ */
