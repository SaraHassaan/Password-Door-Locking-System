/*
 * dc_motor.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Sara
 */

#include"dc_motor.h"

/*initialize Dc motor*/
void Init_Dc_Motor()
{
	/*make 2 pins of mc that connected to 2 input of dc motor are output pins by set them*/
	 SET_BIT(DDIR_PORT_DC,Line1 );
	 SET_BIT(DDIR_PORT_DC,Line2 );
    /*make initial operation of dc motor is to be stopped (not work) by clear 2 output pins that connected to dc motor */
	 CLEAR_BIT(PORT_DC,Line1);
	 CLEAR_BIT(PORT_DC,Line2);
}

/*to make dc motor work at clock wise direction ..make first pin is low and second is high*/
void Clk_Wise()
{
	CLEAR_BIT(PORT_DC,Line1);
	SET_BIT(PORT_DC,Line2);
}

/*to make dc otor work at anti clock wise ..make first pin is high and second pin is low*/
void Anti_Clk_Wise()
{
	SET_BIT(PORT_DC,Line1);
	CLEAR_BIT(PORT_DC,Line2);
}

/*stop motor*/
void Stop_Motor()
{
    CLEAR_BIT(PORT_DC,Line1);
	CLEAR_BIT(PORT_DC,Line2);
}
