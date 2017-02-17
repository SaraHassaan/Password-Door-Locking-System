/*
 * uart.c
 *
 *  Created on: ??�/??�/????
 *      Author: Sara
 */


#include"uart.h"

uint8 i =0;
uint8 correct=0;
void init_uart()
{
	UCSRA=(1<<U2X); //use double transmission speed
	UCSRB=(1<<TXEN)|(1<<RXEN)|(1<<RXCIE); //enable transmit and receive..enable interrupt of receiving
	UCSRC=(1<<UCSZ0)|(1<<UCSZ1)|(1<<URSEL); //transmit and receive 8 bits ..ursel=1 because i write in UCSRC REG
	//UBRRL=(uint8)(MYUPRR); //for choose baudrate..MYUPRR IS 16 bits..first of 8 bits in REGL and laste of 8 bits in regH
	//UBRRH=(uint8)(MYUPRR>>8);
	UBRRL=0xc;
	UBRRH=0x0;
}

void send_byte(uint8 data)
{
	/*
	 * when buffer of transmit data is empty , HW set UDRE in reg UCSRA
	 */
	while(IS_BIT_CLEAR(UCSRA,UDRE)); //wait until the buffer is empty..then send the new data
	UDR=data;

}

uint8 receive_byte()
{
	/*
	 * wait for complete received data when RXC=1
	 */
	while(IS_BIT_CLEAR(UCSRA,RXC));
	return UDR;

}

void send_string(uint8 *str)
{
	uint8 i =0;
	while(str[i] != '\0')
	{
		send_byte(str[i]);
		i++;
	}
	send_byte(str[i]);/*to send null with characters*/
}

void receive_string(uint8 *str)
{
	uint8 i =0;
	str[i]=receive_byte();
	while(str[i] != '\0') /*'\0'is symbol for the end of string*/
	{
		i++;
		str[i]=receive_byte();
	}
}
ISR(USART_RXC_vect)
{
    correct=UDR;

}

