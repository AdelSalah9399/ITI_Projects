/*
 * main.c
 *
 *  Created on: May 8, 2023
 *      Author: Adel
 */



#include <util/delay.h>
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LED/Led_Configuration.h"
#include "../HAL/Switch/Switch_Interface.h"
#include "../HAL/LCD/Lcd_Interface.h"
#include "../HAL/KeyPad/KPD_Interface.h"
#include "../MCAL/Timer/Timer2/Timer2_Interface.h"
#include "../MCAL/ADC/ADC_Interface.h"


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
