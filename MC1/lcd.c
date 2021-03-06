/*
 * lcd.c
 *
 *  Created on: ??�/??�/????
 *      Author: Sara
 */


#include "lcd.h"

void Init_Lcd()
{
     CTRL_PORT_DIR |= (1<<RS)|(1<<RW)|(1<<E); //rs,rw,e is output pins

     #if(bit_mode==4) //if we define the bit mode is 4 and lines is 2 u
         #ifdef higher_pins       /*if define using the highest pins in port of data*/
	     PORT_DATA_DIR=0xf0;
         #else                   /*if use the first 4 pins in port of data*/
	     PORT_DATA_DIR=0x0f;
         #endif
	     LCD_Send_Command(0x02); /*enable 4 bit mode in lcd*/
	     LCD_Send_Command(0x28); /*use 2 line +4 bit mode*/
     #elif(bit_mode==8 ) /*if we define bit mode is 8 */
	     PORT_DATA_DIR=0xff;      /* all port of data is output*/
	     LCD_Send_Command(0x38);
     #endif

	 LCD_Send_Command(0x0c); //enable cursor but hide it
	 Clear_Lcd(); //function to clear lcd
}

/* this function to send command to lcd to execute it ..like clear lcd ,begin cursor, using bit mode of lcd ..etc*/
void LCD_Send_Command(uint8 command)
{

	 CLEAR_BIT(CTRL_PORT,RS); //RS=0 BECAUSE I WANT LCD TO EXECUTE COMMAND
	 CLEAR_BIT(CTRL_PORT,RW); //I WILL WRITE NOT READ ON LCD
	 _delay_ms(1);
	 SET_BIT(CTRL_PORT,E); //Enable lcd
	 /*using bit mode 4 , make you to send data at 2 stages ..first moving most significant
	  * secondly moving least significant bits
	  * */
     #if(bit_mode==4)     /* each if with its end if */
         #ifdef higher_pins /* if the last pins is output in data port ..pc4..pc7*/
	     PORT_DATA_PATH=(command & 0xf0); /*move the most significant bits of command to last pins of data port(pc4..pc7)*/
         #else
	     PORT_DATA_PATH=((command >> 4)& 0x0f);/*shift right the most significant pins(d4..d7) by 4 and move them to the first pins of data port*/
         #endif
	 _delay_ms(1);
	 CLEAR_BIT(CTRL_PORT,E); //E=0
	 _delay_ms(1);
	 SET_BIT(CTRL_PORT,E);  //E=1
        #ifdef higher_pins
	    PORT_DATA_PATH=((command << 4)&0xf0); /*shift left the least significant bits (c0..c3) and move them to data port(pc4..pc7)*/
        #else
	    PORT_DATA_PATH=(command & 0x0f); /*move the least significant bits of command to port (pd0..pd3)*/
        #endif
	 _delay_ms(1);
	 CLEAR_BIT(CTRL_PORT,E);
	 _delay_ms(1);
     #elif(bit_mode==8)/* if using bit mode 8*/
	    PORT_DATA_PATH=command; /*move all bits of command to port pc0..pc7*/
		 _delay_ms(1);
		 CLEAR_BIT(CTRL_PORT,E);
		 _delay_ms(1);
     #endif

}

/*lcd_send_data ..send the string to it to show the string on lcd ..string is sent char by char*/
void Lcd_Send_Data(uint8 data)
{
	SET_BIT(CTRL_PORT,RS); //RS=1 BECAUSE I WANT LCD TO show data on lcd
		 CLEAR_BIT(CTRL_PORT,RW); //I WILL WRITE NOT READ ON LCD
		 _delay_ms(1);
		 SET_BIT(CTRL_PORT,E); //Enable lcd
		 /*using bit mode 4 , make you to send data at 2 stages ..first moving most significant
		  * secondly moving least significant bits
		  * */
	     #if(bit_mode==4)     /* each if with its end if */
	         #ifdef higher_pins /* if the last pins is output in data port ..pc4..pc7*/
		     PORT_DATA_PATH=(data & 0xf0); /*move the most significant bits of command to last pins of data port(pc4..pc7)*/
	         #else
		     PORT_DATA_PATH=((data >> 4)& 0x0f);/*shift right the most significant of data(d4..d7) by 4 and move them to the first pins of data port*/
	         #endif
		 _delay_ms(1);
		 CLEAR_BIT(CTRL_PORT,E); //E=0
		 _delay_ms(1);
		 SET_BIT(CTRL_PORT,E);  //E=1
	        #ifdef higher_pins
		    PORT_DATA_PATH=((data << 4)&0xf0); /*shift left the least significant bits (d0..d3) and move them to data port(pc4..pc7)*/
	        #else
		    PORT_DATA_PATH=(data& 0x0f); /*move the least significant bits of data to port (pc0..pc3)*/
	        #endif
		 _delay_ms(1);
		 CLEAR_BIT(CTRL_PORT,E);
		 _delay_ms(1);
	     #elif(bit_mode==8)/* if using bit mode 8*/
		    PORT_DATA_PATH=data; /*move all bits of command to port pc0..pc7*/
			 _delay_ms(1);
			 CLEAR_BIT(CTRL_PORT,E);
			 _delay_ms(1);
	     #endif
}

/*to determine the position of cursor to write in the right location on lcd
 * its take two parameter the line and the column of lcd that u want to write at
 */

void Cursor_Location(uint8 row , uint8 col)
{
	uint8 address;
	uint8 cursor_address;
	switch(row)
	{
	   case 0: address=col;
	           break;
	   case 1: address=0x40+col; /* 0x40 is the location of first col and second row in lcd ..0x40+col to get the location at this row and this coulmn*/
	           break;
	   case 2: address=0x10+col;
	           break;
	   case 3: address=0x50+col;
	           break;
	}
	cursor_address = 0x80|address; /*0x80 is the beginning of the cursor ,we make or to get the location of cursor at this row and this col*/
	LCD_Send_Command(cursor_address);
}

/*...Lcd_Display_String...str is pointer point to one char in the string
  using pointer to char because i will send one char to
display function one by one ..i dont send all the string(array of char) in one time*/
void Lcd_Display_String(const uint8 * str)
{
	while((*str)!='\0')
	{
		Lcd_Send_Data(*str);
		 str++; // to access the locations under str pointer to get the rest of characters in string

	}

}
/* row_col_string ..it recieves the location of row and column that you will write at
 * and recieve the string that will be showed on lcd
 */
void Row_Col_string(uint8 row, uint8 col , const uint8 *str)
{
	Cursor_Location(row,col);
	Lcd_Display_String(str);

}
/*if you want to show intger on lcd ..integer must be converted to char */

void Int_To_String( int num)
{
	uint8 buffer[16]; //lcd contains 16 column
	itoa(num,buffer,10); /*itoa is function convert the integer to character ..put the char in char of array buffer ..10 because the number is decimal not hexa not octal*/
	//Cursor_Location(row,col);
	Lcd_Display_String(buffer); // send the address of first array to Lcd_Display_String to show it on lcd*/
}

void Clear_Lcd()
{
	LCD_Send_Command(0x01); //0x01 for clear any words on lcd

}

void clear_char()
{
	LCD_Send_Command(0x10); /*move cursor left by one character*/
	Lcd_Send_Data('\0 ');  /*put null on this character*/
	_delay_ms(500);        /*time of pressed*/
	LCD_Send_Command(0x10); /*move cursor left by one character again to enable u delete another
				                           character after deleting one or enable you to write character its
				                           position after deleting one directly*/
}
