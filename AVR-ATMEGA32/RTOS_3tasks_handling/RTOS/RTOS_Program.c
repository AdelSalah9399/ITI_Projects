/*
 * RTOS_Program.c
 *
 *  Created on: Apr 11, 2023
 *      Author: Adel
 */

#include "../../common/BIT_MATH.h"
#include "../../common/STD_TYPE.h"

#include "../Timer0/Timer0_Interface.h"
#include "../RTOS_GIE/RTOS_GIE_Interface.h"

#include "RTOS_Interface.h"
#include "RTOS_Private.h"
#include "RTOS_Config.h"
#include "../Timer0/Timer0_Config.h"

Task_t SysTasks[TaskNumber]={{NULL}};

void RTOS_Start(void)
{
	T0_SetCallBack(voidScheduler);
	RTOS_GIE_ENABLE();
	Timer0Init();
}

RTOS_ERR RTOS_CreatTask(u8 priority,u16 periodicity,void (*pvTaskFunc)(void),u16 FirstDelay)
{
	if(SysTasks[priority].TaskFunc==NULL)
	{
	SysTasks[priority].periodicity=periodicity;
	SysTasks[priority].TaskFunc=pvTaskFunc;
	SysTasks[priority].State=TaskResumed;
	SysTasks[priority].FirstDelay=FirstDelay;
	}
	else
	{
		/*task is reserved*/
		return Err_Task;
	}
	return RTOSNOERR;
}

void RTOS_TaskSuspend(u8 priority)
{
	SysTasks[priority].State = TaskSuspend;
}
void RTOS_TaskResume(u8 priority)
{
	SysTasks[priority].State = TaskResumed;
}

void RTOS_DeleteTask(u8 priority)
{
	SysTasks[priority].TaskFunc=NULL;
}

static void voidScheduler(void)
{
	u8 local_TaskCouner;

	for(local_TaskCouner=0;local_TaskCouner<TaskNumber;local_TaskCouner++)
	{
		if(SysTasks[local_TaskCouner].State==TaskResumed)
		{
			/***************************Apply FIRST DELAY IDEA*******************/
			if((SysTasks[local_TaskCouner].FirstDelay)==0)
			{
				if(SysTasks[local_TaskCouner].TaskFunc!=NULL)
				{
						SysTasks[local_TaskCouner].TaskFunc();
						SysTasks[local_TaskCouner].FirstDelay=(SysTasks[local_TaskCouner].periodicity-1);
				}
				else
				{
					(SysTasks[local_TaskCouner].FirstDelay)--;
				}/**************************************************************************/
			}
		}
	}
}

