/*
 * RTOS_Interface.h
 *
 *  Created on: Apr 11, 2023
 *      Author: Adel
 */

#ifndef RTOS_STACK_RTOS_RTOS_INTERFACE_H_
#define RTOS_STACK_RTOS_RTOS_INTERFACE_H_
#include "../../common/BIT_MATH.h"
#include "../../common/STD_TYPE.h"


void RTOS_Start(void);


//RTOS_ERR RTOS_CreatTask(u8 priority, u16 periodicity, void (*pvTaskFunc)(), u16 FirstDelay);

void RTOS_TaskSuspend(u8 priority);

void RTOS_TaskResume(u8 priority);

void RTOS_DeleteTask(u8 priority);

#endif /* RTOS_STACK_RTOS_RTOS_INTERFACE_H_ */
