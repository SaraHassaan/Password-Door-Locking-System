/*
 * timer.c
 *
 *  Created on: ??�/??�/????
 *      Author: Sara
 */
#include "timer.h"

uint8 Tick;
uint8 flag_o=0;
void Timer_int()
{
	/*enable (TIMER0)normal mode  ,Ftimer=Fcpu/1028 ..choose prescaler=1028*/
	TCCR0=(1<<FOC0)|(1<<CS02)|(1<<CS00);
	TCNT0=5; //initial value
    TIMSK|=(1<<TOIE0);// TOIE0 (Timer/Counter0 Overflow Interrupt Enable)
    SET_BIT(SREG,7);

}
ISR(TIMER0_OVF_vect)
{
	Tick++;
	//TIFR &=~(1<<TOV0); //Timer/Counter0 Overflow Flag(automatic flag) myzt avr hwa by3mlhabzero b3d isr ma t5ls
	if(Tick==40)
	{
		//Stop_Motor();
		Tick=0;
		Tick=0;
		flag_o=1;
		//send_byte('c');
	}
}
