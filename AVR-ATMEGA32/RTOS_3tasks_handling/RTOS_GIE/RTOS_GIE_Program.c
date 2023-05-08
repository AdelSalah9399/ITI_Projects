/*
 * RTOS_GIE_Program.c
 *
 *  Created on: Apr 11, 2023
 *      Author: Adel
 */
#include "RTOS_GIE_Register.h"
#include "RTOS_GIE_Interface.h"
#include "../../common/BIT_MATH.h"
#include "../../common/STD_TYPE.h"
#include"../../MCAL/DIO/DIO_Interface.h"




void RTOS_GIE_ENABLE(void)
{
	SET_BIT(SREG,PIN7);
}
void RTOS_GIE_DISABLE(void)
{
	CLR_BIT(SREG,PIN7);
}
