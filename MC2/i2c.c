/*
 * i2c.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Sara
 */

#include"i2c.h"
#include"external_eeprom.h"
void i2c_init()
{
	//TWCR = (1<<TWEN);/*enable i2c*/
	TWBR = 0x02;// to choose bit rate of i2c ..for frequency of i2c
	TWSR &= 0xfc; //Prescaler Value=1 for freq clk of i2c
	TWSR = 0x00;
	TWAR=0x01;//its my address of my micro controller,if any another device want to contact me when am slave by this address


}
void start_bit_i2c()
{

	TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWSTA);//clear flag , enable TWI and send start bit
	while( IS_BIT_CLEAR(TWCR,TWINT));//wait until start bit is transmitted

}

void stop_bit_i2c()
{

	TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWSTO);//clear flag , enable TWI and send stop bit
	while( IS_BIT_SET(TWCR,TWSTO));//wait until stop bit is executed

}

void write_i2c(uint8 data)
{
	TWDR=data;//for transmit data
	TWCR=(1<<TWEN)|(1<<TWINT);// enable TWI and clear the TWI interrupt flag (automatic flag)
	while( IS_BIT_CLEAR(TWCR,TWINT)); //wait until TWINT is set by hardware for transfer is complete


}

uint8 read_byte_ack_i2c()
{
	TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWEA);// enable TWI and clear the TWI interrupt flag (automatic flag)..enable acknowledgment
	while( IS_BIT_CLEAR(TWCR,TWINT)); //wait until receive is complete
	return TWDR;  //TWDR is the register that receive data
}

uint8 read_byte_Nack_i2c()
{
	TWCR=(1<<TWEN)|(1<<TWINT);// enable TWI and clear the TWI interrupt flag (automatic flag)
	while( IS_BIT_CLEAR(TWCR,TWINT));//wait until receive is complete
	return TWDR;  //TWDR is the register that receive data

}

uint8 read_status_i2c() //this function to read what happen on buses of i2c ..by read the reg TWSR
{
	uint8 status;
	status= (TWSR & 0xf8); /*the last of 5 bits indicates status of the TWI logic and the Two-wire Serial Bus
	                        so we make TWSR & with 1111 1000 ..write zeros on 3 first bits*/
	return status;

}


