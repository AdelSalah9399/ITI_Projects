/*
 * main.c
 *
 *  Created on: May 8, 2023
 *      Author: Adel
 */



#include <util/delay.h>
#include "../HAL/LED/Led_Configuration.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LED/Led_Private.h"
#include "../HAL/SeV_Seg/SeVseg_interface.h"
#include "../HAL/Switch/Switch_Interface.h"
#include "../HAL/LCD/Lcd_Interface.h"
#include "../HAL/KeyPad/KPD_Interface.h"
#include "../MCAL/EXTI_post/EXTI_Register.h"
#include "../MCAL/EXTI_post/EXTI_Interface.h"
#include "../MCAL/Timer/Timer2/Timer2_Register.h"
#include "../MCAL/Timer/Timer2/Timer2_Config.h"
#include "../MCAL/Timer/Timer2/Timer2_Interface.h"
#include "../MCAL/ADC/ADC_Config.h"
#include "../MCAL/ADC/ADC_Register.h"
#include "../MCAL/ADC/ADC_Private.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include "../HAL/Switch/Switch_Configuration.h"
#include "../HAL/Switch/Switch_Private.h"
#include "../MCAL/UART/UART_Interface.h"
#include "../MCAL/UART/UART_Register.h"
#include "../MCAL/UART/UART_Config.h"
#include "../MCAL/UART/UART_Private.h"
#include "../MCAL/EXTI_pre/EXTI_pre_Interface.h"
#include "../MCAL/TWI/TWI_Interface.h"
#include "../HAL/EEPROM/EEPROM_Interface.h"
#include "../RTOS_Stack/Timer0/Timer0_Config.h"
#include "../RTOS_Stack/Timer0/Timer0_Interface.h"
#include "../RTOS_Stack/Timer0/Timer0_Register.h"
#include "../RTOS_Stack/RTOS/RTOS_Interface.h"




void main()
{

	KPD_INFO KPD={Groub_B,PIN0,Groub_B,PIN1,Groub_B,PIN2,Groub_B,PIN3,Groub_B,PIN4,Groub_B,PIN5,Groub_B,PIN6,Groub_B,PIN7};
	Lcd_Info LCD={Groub_A,Groub_A,Groub_A,PIN0,PIN1,PIN2,Groub_C};
	DIO_ErrStateSetPinDirection(Groub_D,PIN7,DIO_OUTPUT);

	KPD_INIT(&KPD);
	Lcd_VoidInit(&LCD);
	Timer2Init();
	FastPWM_INV_NonInv();
	//Timer2_OF_PIE_INTEnable();
	//Timer2_CMPMatch_PIE_INTEnable();

	u8 res;
	u8 LCD_Interface[15]="Enter the PWM:";

	u8 hund=0;
	u8 tens=0;
	u8 ones=0;
	u8 total_Duty=0;
	u8 counter=0;

	Lcd_VoidSendString(LCD_Interface,&LCD);
	Lcd_VoidGoXY(&LCD,1,0);
	while(1)
	{
		while(res!='=')
		{
			res=KeyPad(&KPD);
			if(res)
			{
				if(counter==0)
				{	hund=res;
					Lcd_VoidGoXY(&LCD,1,0);
					Lcd_VoidSendNumForTimers(res,&LCD);
					counter=1;
				}
				else if(counter==1)
				{	tens=res;
					Lcd_VoidGoXY(&LCD,1,1);
					Lcd_VoidSendNumForTimers(res,&LCD);
					counter=2;
				}
				else if(counter==2)
				{	ones=res;
					Lcd_VoidGoXY(&LCD,1,2);
					Lcd_VoidSendNumForTimers(res,&LCD);
					counter=3;
				}
			}
			Lcd_VoidGoXY(&LCD,1,3);
		}
		total_Duty=(hund*100)+(tens*10)+ones;
		OCR2_CompValue(total_Duty);
	}
}
