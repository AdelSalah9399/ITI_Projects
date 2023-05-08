/*****************************************************************************************************************************************/
/*														Assignment(2)   																 */
/*														Assignment(2)   																 */
/*										7-Segmant counter 1:99 using only one port (9pins)												 */
/*****************************************************************************************************************************************/
#include "../MCAL/DIO/DIO_Interface.h"
#include<util/delay.h>

#define num0 0x3F
#define num1 0x06
#define num2 0x5B
#define num3 0x4F
#define num4 0x66
#define num5 0x6D
#define num6 0x7D
#define num7 0x07
#define num8 0x7F
#define num9 0x6F


void main()
{	u8 SEG1,SEG2;
u8 _7seg[10]={num0,num1,num2,num3,num4,num5,num6,num7,num8,num9};
ErrState Res[6]={0};
Res[0]=DIO_ErrStateSetGroubDirection(Groub_C,MAX_RANG);
Res[1]=DIO_ErrStateSetGroubDirection(Groub_D,MAX_RANG);
while(1)
{
	for(SEG1=0 ; SEG1<=9 ; SEG1++)
	{
		for(SEG2=0 ; SEG2<=9 ; SEG2++)
		{
			DIO_ErrStateSetPinValue(Groub_D,PIN0,0);
			DIO_ErrStateSetPinValue(Groub_D,PIN1,1);
			DIO_ErrStateSetGroubValue(Groub_C,_7seg[SEG2]);
			_delay_ms(90);
			DIO_ErrStateSetPinValue(Groub_D,PIN0,1);
			DIO_ErrStateSetPinValue(Groub_D,PIN1,0);
			DIO_ErrStateSetGroubValue(Groub_C,_7seg[SEG1]);
			_delay_ms(90);
		}
			DIO_ErrStateSetPinValue(Groub_D,PIN0,0);
			DIO_ErrStateSetPinValue(Groub_D,PIN1,1);
			DIO_ErrStateSetGroubValue(Groub_C,_7seg[10]);
	}

	
}
}

/*===========================================================DONE==========================================================================*/
/*===========================================================DONE==========================================================================*/
/*===========================================================DONE==========================================================================*/
/*===========================================================DONE==========================================================================*/
