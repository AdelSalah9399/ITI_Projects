/*
 * Timer_Interface.h
 *
 *  Created on: Apr 1, 2023
 *      Author: Adel
 */

#ifndef MCAL_TIMER_TIMER2_TIMER0_INTERFACE_H_
#define MCAL_TIMER_TIMER2_TIMER0_INTERFACE_H_


void Timer0Init(void);

void T0_SetCallBack(void (*APPfunc)(void));



#endif /* MCAL_TIMER_TIMER2_TIMER0_INTERFACE_H_ */
