/*
 * RTOS_Private.h
 *
 *  Created on: Apr 11, 2023
 *      Author: Adel
 */

#ifndef RTOS_STACK_RTOS_RTOS_PRIVATE_H_
#define RTOS_STACK_RTOS_RTOS_PRIVATE_H_
#include "../../common/BIT_MATH.h"
#include "../../common/STD_TYPE.h"

typedef enum
{
	RTOSNOERR,
	Err_Task
}RTOS_ERR;


typedef struct
{
	u16 periodicity;
	void (*TaskFunc)(void);
	u8 State;
	u16 FirstDelay;
}Task_t;

static void voidScheduler(void);

#define TaskSuspend  1
#define TaskResumed  2

#endif /* RTOS_STACK_RTOS_RTOS_PRIVATE_H_ */
