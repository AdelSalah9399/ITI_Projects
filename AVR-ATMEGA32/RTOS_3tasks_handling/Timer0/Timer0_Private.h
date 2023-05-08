/*
 * Timer_Private.h
 *
 *  Created on: Apr 1, 2023
 *      Author: Adel
 */

#ifndef MCAL_TIMER_TIMER2_TIMER2_PRIVATE_H_
#define MCAL_TIMER_TIMER2_TIMER2_PRIVATE_H_


/*Modes*/
#define Normal_Mode 	1
#define CTC_Mode		2
#define PWM_Mode		3
#define Fast_PWM_Mode	4

/*CTC-OC2 Options*/
#define Normal_port	    1
#define Toggle_OC2		2
#define Clear_OC2		3
#define Set_OC2			4

/*Timer ON/OFF*/
#define ON 		1
#define OFF 	2

/*Clock-NORMAL MODE- Prescaler options*/
#define NO_PreScalling		1
#define _8_PreScalling		2
#define _32_PreScalling		3
#define _64_PreScalling		4
#define _128_PreScalling	5
#define _256_PreScalling	6
#define _1024_PreScalling	7


/*TIMER INTERRUPT ENABLE*/
#define ENABLE 			1
#define DISABLE 		2


///////////////////////////////////////////////////////////////////////////////




#endif /* MCAL_TIMER_TIMER2_TIMER2_PRIVATE_H_ */
