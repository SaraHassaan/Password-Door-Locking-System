/*
 * uart.h
 *
 *  Created on: ??�/??�/????
 *      Author: Sara
 */

#ifndef UART_H_
#define UART_H_

#include"macro.h"
#include"micro_config.h"
#include"std_types.h"

#define baud 9600
#define MYUPRR   (F_CPU/(8*baud))-1

extern uint8 recv_byte;
extern uint8 str_recv[5];
void init_uart();
void send_byte(uint8 data);
uint8 receive_byte();
void send_string(uint8 *str);
void receive_string(uint8 *str);

#endif /* UART_H_ */
