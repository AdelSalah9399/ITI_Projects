/*
 * Timer_Register.h
 *
 *  Created on: Apr 1, 2023
 *      Author: Adel
 */

#ifndef MCAL_TIMER_TIMER2_TIMER0_REGISTER_H_
#define MCAL_TIMER_TIMER2_TIMER0_REGISTER_H_

#define TCCR0 (*(volatile u8*)(0x53))
#define TCNT0 (*(volatile u8*)(0x52))
#define TIMSK (*(volatile u8*)(0x59))
#define OCR0  (*(volatile u8*)(0x5C))

#endif /* MCAL_TIMER_TIMER2_TIMER0_REGISTER_H_ */
