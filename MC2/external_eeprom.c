/*
 * external_eeprom.c
 *
 *  Created on: ??ş/??ş/????
 *      Author: Sara
 */


#include"external_eeprom.h"




/*this function receive the address of memory location of eeprom
  the place that data will stored at to transmit it to i2c and receive data */
uint8 write_eeprom(uint16 address,uint8 data)
{
	start_bit_i2c();
	if(read_status_i2c() != 0x08) /*ask if reg status =0x08 (0x08 indicate that start bit is transmitted at bus of i2c)*/
		return 0;                 /*return false*/
	/*A is fixed the last 4 bits if address of eeprom ..(address & 0x0700)for take the bits of address number 10,9,8
	 * and transmit write bit( (1010 0000 | (0000 0111 0001 0001 & 0000 0111 0000 0000)>>7 ... 0000 1110)
	 */
	write_i2c((uint8)(0xA0 | ((address & 0x0700)>>7)));
	if(read_status_i2c() != 0x18)      /*master transmit slave address +R/W bit+ack received*/
		return 0;
	write_i2c((uint8)(address)); /*transmit the rest of device address to i2c*/
	if(read_status_i2c() != 0x28) /*master transmit data and ack has been received from slave*/
		return 0;
	write_i2c(data); /*transmit data that will be stored at eeprom */
	if(read_status_i2c() != 0x28)
		return 0;
	stop_bit_i2c();
	return 1; /* the task is finished*/
}

/*
 * this function to read data from eeprom ..firstly you send start bit
 * 2- send device address + bit of A10 A9 A8 of 11 bits of memory location of eeprom + 0 for write on i2c
 * 3-send the rest of address of memory location A0..A7
 * 4-send repeated start
 * 5-send slave address + read bit (1)
 * 6-receive the data by using pointer
 */
uint8 read_eeprom(uint16 address,uint8 *ptr_data)
{
	start_bit_i2c();
	if(read_status_i2c() != 0x08)
		return 0;
	write_i2c((uint8)(0xA0 | ((address & 0x0700)>>7)));
	if(read_status_i2c() != 0x18)
		return 0;
	write_i2c((uint8)(address));
	if(read_status_i2c() != 0x28)
		return 0;
	start_bit_i2c(); /*repeated start bit*/
	if(read_status_i2c() != 0x10)/* 0x10 for repeated start bit*/
		return 0;
	write_i2c((uint8)((0xA0) | ((address & 0x0700)>>7) | 1));/*send device address that will connect with it + read bit*/
	if(read_status_i2c() != 0x40) /*0x40 for transmit data + read bit+ack received*/
		return 0;
	*ptr_data=read_byte_Nack_i2c(); /*the location that ptr_data point it ,it will contain data that you want to read*/
	if(read_status_i2c() != 0x58)   /*0x58 indicates master receive data and doesnt send acknowledgment*/
		return 0;
	stop_bit_i2c();
	return 1; /*1 indicates success operation*/
}
