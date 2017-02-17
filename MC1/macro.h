/*
 * macro.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Sara
 */

#ifndef MACRO_H_
#define MACRO_H_

#define SET_BIT(REG,BIT) (REG |=(1<<BIT)) //put 1 IN a pin in reg (e.g make a pin is output pin..reg like DDRX(IN AVR) )

#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT))) //put 0 IN a pin in reg (make a pin is input pin..reg like DDRX(IN AVR) )

#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))  //toggle pin in reg (0 to 1 or 1 to 0)

#define ROR(REG,NUM) (REG=(REG>>NUM)|(REG<<8-NUM)) // rotate rigt the bits in the reg by num (e.g 2)

#define ROL(REG,NUM)  (REG=(REG<<NUM)|(REG>>8-NUM) //rotate left the bits in the reg by num

#define IS_BIT_SET(REG,BIT)(REG & (1<<BIT)) // when check about 1 for bit in reg (reg like PINA IN avr ..bit is the pin number in port)

#define  IS_BIT_CLEAR(REG,BIT)(!(REG & (1<<BIT))) //when check about zero for bit in reg

#endif /* MACRO_H_ */
