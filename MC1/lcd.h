/*
 * lcd.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Sara
 */

#ifndef LCD_H_
#define LCD_H_

#include"macro.h"
#include"std_types.h"
#include"micro_config.h"

#define bit_mode 8 /*because i will use lcd with 8 bit mode*/

/*prototypes of functions that are used in code */

void Init_Lcd();
void LCD_Send_Command(uint8 command);
void Lcd_Send_Data(uint8 data);
void Cursor_Location(uint8 row , uint8 col);
void Lcd_Display_String(const uint8 * str);
void Row_Col_string(uint8 row, uint8 col , const uint8 *str);
void Int_To_String( int num);
void Clear_Lcd();
void clear_char();

/*control pins on lcd */
#define RS PD4 /*for command (rs=0)and data(rs=1)*/
#define RW PD5 /*read or write data*/
#define E  PD6 /* enable lcd*/

/*ports that used in lcd*/
#define CTRL_PORT_DIR DDRD/*PB1,PB2,PB3 are pins for control lcd */
#define CTRL_PORT     PORTD /*to write on PORTB use this reg*/
#define PORT_DATA_DIR DDRC  /*portD is used for data path in lcd*/
#define PORT_DATA_PATH  PORTC

#endif /* LCD_H_ */
