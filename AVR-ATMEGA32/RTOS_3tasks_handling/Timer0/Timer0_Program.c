/*
 * Timer_Program.c
 *
 *  Created on: Apr 1, 2023
 *      Author: Adel
 */
#include"Timer0_Config.h"
#include"Timer0_Interface.h"
#include"Timer0_Private.h"
#include"Timer0_Register.h"
#include"../../MCAL/DIO/DIO_Interface.h"

void (*ptrtofunc)(void)=NULL;


void Timer0Init()
{
#if TIMER0_OnOff == ON
		/*CTC_Mode*/
		CLR_BIT(TCCR0,PIN3);
		SET_BIT(TCCR0,PIN6);
#else
#error"Timer is OFF"

#endif
#if TIMER0_OnOff == ON
	#if T0_NM_Presaclling_Value==NO_PreScalling
		SET_BIT(TCCR0,PIN0);
		CLR_BIT(TCCR0,PIN1);
		CLR_BIT(TCCR0,PIN2);
	#elif T0_NM_Presaclling_Value==_8_PreScalling
		CLR_BIT(TCCR0,PIN0);
		SET_BIT(TCCR0,PIN1);
		CLR_BIT(TCCR0,PIN2);
	#elif T0_NM_Presaclling_Value==_32_PreScalling
		SET_BIT(TCCR0,PIN0);
		SET_BIT(TCCR0,PIN1);
		CLR_BIT(TCCR0,PIN2);
	#elif T0_NM_Presaclling_Value==_64_PreScalling
		CLR_BIT(TCCR0,PIN0);
		CLR_BIT(TCCR0,PIN1);
		SET_BIT(TCCR0,PIN2);
	#elif T0_NM_Presaclling_Value==_128_PreScalling
		SET_BIT(TCCR0,PIN0);
		CLR_BIT(TCCR0,PIN1);
		SET_BIT(TCCR0,PIN2);
	#elif T0_NM_Presaclling_Value==_256_PreScalling
		CLR_BIT(TCCR0,PIN0);
		SET_BIT(TCCR0,PIN1);
		SET_BIT(TCCR0,PIN2);
	#elif T0_NM_Presaclling_Value==_1024_PreScalling
		SET_BIT(TCCR0,PIN0);
		SET_BIT(TCCR0,PIN1);
		SET_BIT(TCCR0,PIN2);
	#else
		#error "WRONG MODE CONFIGRATION"
	#endif
#else
#error"Timer is OFF"

#endif
#if CTC_OC0_mode == Normal_port
	CLR_BIT(TCCR0,PIN4);
	CLR_BIT(TCCR0,PIN5);
#elif CTC_OC0_mode == Toggle_OC2
	SET_BIT(TCCR0,PIN4);
	CLR_BIT(TCCR0,PIN5);
#elif CTC_OC0_mode == Clear_OC2
	CLR_BIT(TCCR0,PIN4);
	SET_BIT(TCCR0,PIN5);
#elif CTC_OC0_mode == Set_OC2
	SET_BIT(TCCR0,PIN4);
	SET_BIT(TCCR0,PIN5);
#else
	#error"WRONG OC2 CONFIGRATION"
#endif
#if T0_CTC_INT==ENABLE
	SET_BIT(TIMSK,PIN1);
#elif T0_CTC_INT==DISABLE
	CLR_BIT(TIMSK,PIN1);
#else
	#error "WRONG CONFIGRATION"
#endif

OCR0=Comp_Value ;
}


/************************************************CALLBACK MECHANISM*****************************************************/

void T0_SetCallBack(void (*APPfunc)(void))
{
	if(APPfunc!=NULL)
	{
		ptrtofunc=APPfunc;  // make the ptr = argument
	}
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if(ptrtofunc!=NULL)
	{
		ptrtofunc(); //call the ptr
	}
}








