/*
 * Timer2_Config.h
 *
 *  Created on: Apr 1, 2023
 *      Author: Adel
 */

#ifndef RTOS_STACK_TIMER0_TIMER0_CONFIG_H_
#define RTOS_STACK_TIMER0_TIMER0_CONFIG_H_

/*Timer Mode*/
/*CTC ONLT*/

/*TIMER ON/OFF*/
#define TIMER0_OnOff ON

/*Clock-NORMAL MODE- Prescaling options*/
#define T0_NM_Presaclling_Value			 _64_PreScalling

#define Comp_Value							125

/*CTC-OC2 MODE*/
#define CTC_OC0_mode 						Normal_port

/*TIMER INTERRUPT ENABLE*/
#define T0_CTC_INT 						ENABLE


#endif /* RTOS_STACK_TIMER0_TIMER0_CONFIG_H_ */
