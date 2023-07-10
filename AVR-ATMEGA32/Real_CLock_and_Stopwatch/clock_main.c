
#include <util/delay.h>
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/Switch/Switch_Interface.h"
#include "../HAL/LCD/Lcd_Interface.h"
#include "../HAL/KeyPad/KPD_Interface.h"
#include "../MCAL/EXTI_post/EXTI_Interface.h"
#include "../MCAL/Timer/Timer2/Timer2_Interface.h"



/*Global LCD*/
Lcd_Info LCD={Groub_C,Groub_C,Groub_C,PIN0,PIN1,PIN2,Groub_D};


void CLOCK_MODE(void);
void CLK1Sec(void);



void main()
{
	/*******************************************INITIALIZATION************************************************/
	/*Timer Initialization To Generate 1sec */
	EXTI_Enable_GIE();
	Timer2NM_PIE_INTEnable();
	Timer2ModeSetting();
	T2PreScalling();
	Timer2_PreloadValue(192);
	DIO_ErrStateSetPinDirection(Groub_B,PIN0,DIO_OUTPUT);
	SetCallBack(&CLK1Sec);

	/*LCD Initialization*/
	Lcd_VoidInit(&LCD);


	while(1);
}



void CLOCK_MODE(void)
{
			static u8 flag;
			static u8 Clk[9]={'0','3',':','5','8',':','0','0'};
			static u8 AM_PM[3]={'A','M'};
			if(flag==0)
			{
				Lcd_VoidSendString(Clk,&LCD);
				/* WINDOW INTERFACE PRINTING */
				Lcd_VoidGoXY(&LCD,0,11);
				Lcd_VoidSendString(AM_PM,&LCD);
				Lcd_VoidGoXY(&LCD,1,5);
				Lcd_VoidSendChar('C',&LCD);
				Lcd_VoidGoXY(&LCD,1,6);
				Lcd_VoidSendChar('L',&LCD);
				Lcd_VoidGoXY(&LCD,1,7);
				Lcd_VoidSendChar('O',&LCD);
				Lcd_VoidGoXY(&LCD,1,8);
				Lcd_VoidSendChar('C',&LCD);
				Lcd_VoidGoXY(&LCD,1,9);
				Lcd_VoidSendChar('K',&LCD);
			}

		do{
			if((Clk[6]<'6'))
			{
				if(Clk[7]<'9')
					{
					Clk[7]++;
					Lcd_VoidGoXY(&LCD,0,7);
					Lcd_VoidSendNumForTimers(Clk[7],&LCD);
					flag=1;
					continue;
					}

						Clk[7]='0';
						Lcd_VoidGoXY(&LCD,0,7);
						Lcd_VoidSendNumForTimers(Clk[7],&LCD);
						Clk[6]++;
						Lcd_VoidGoXY(&LCD,0,6);
						if(Clk[6]!='6')Lcd_VoidSendNumForTimers(Clk[6],&LCD);

						continue;
			}     /*-----------------------------------------------MINUTS PART-----------------------------------------------------------*/
			if((Clk[3]<'6'))
			{
				if(Clk[4]<'9')
					{
					Clk[6]='0';
					Lcd_VoidGoXY(&LCD,0,6);
					Lcd_VoidSendNumForTimers(Clk[6],&LCD);
					/////////////////////////////////////////////////////////////////////////
					Clk[4]++;
					Lcd_VoidGoXY(&LCD,0,4);
					Lcd_VoidSendNumForTimers(Clk[4],&LCD);
					continue;
					}
						Clk[4]='0';
						Lcd_VoidGoXY(&LCD,0,4);
						Lcd_VoidSendNumForTimers(Clk[4],&LCD);
						/////////////////////////////////////////////////////////////////////////////////////
						Clk[3]++;
						Lcd_VoidGoXY(&LCD,0,3);
						Lcd_VoidSendNumForTimers(Clk[3],&LCD);
						continue;
			}
			if(Clk[0]<'3')
						{
							if(Clk[1]<'9')
								{
								Clk[3]='0';
								Lcd_VoidGoXY(&LCD,0,3);
								Lcd_VoidSendNumForTimers(Clk[3],&LCD);
								/////////////////////////////////////////////////////////////////////////
								Clk[1]++;

								Lcd_VoidGoXY(&LCD,0,1);
								Lcd_VoidSendNumForTimers(Clk[1],&LCD);
								continue;
								}
									Clk[1]='0';
									Lcd_VoidGoXY(&LCD,0,1);
									Lcd_VoidSendNumForTimers(Clk[1],&LCD);
									/////////////////////////////////////////////////////////////////////////////////////
									Clk[0]++;
									Lcd_VoidGoXY(&LCD,0,0);
									Lcd_VoidSendNumForTimers(Clk[0],&LCD);
									continue;
						}
		}
		while(0);
}


void StopWatch(void)
{
				u8 StartStop;
				Switch_Info StartStop_SW 	   = {Groub_C,PIN5,InternalPullUp};
				SW_SwitchErrStateGetState(&StartStop_SW 	  ,&StartStop );
				if(StartStop==PressedPullUp)
			{
					static u8 flag;
					static u8 Clk[9]={'0','0',':','0','0',':','0','0'};
					if(flag==0)
					{
						Lcd_VoidSendString(Clk,&LCD);
						/* WINDOW INTERFACE PRINTING */
						Lcd_VoidGoXY(&LCD,1,5);
						Lcd_VoidSendChar('S',&LCD);
						Lcd_VoidGoXY(&LCD,1,6);
						Lcd_VoidSendChar('T',&LCD);
						Lcd_VoidGoXY(&LCD,1,7);
						Lcd_VoidSendChar('P',&LCD);
						Lcd_VoidGoXY(&LCD,1,8);
						Lcd_VoidSendChar('W',&LCD);
						Lcd_VoidGoXY(&LCD,1,9);
						Lcd_VoidSendChar('C',&LCD);
						Lcd_VoidGoXY(&LCD,1,10);
						Lcd_VoidSendChar('H',&LCD);
					}

				do{
					if(Clk[6]<'6')
					{
						if(Clk[7]<'9')
							{
							Clk[7]++;
							Lcd_VoidGoXY(&LCD,0,7);
							Lcd_VoidSendNumForTimers(Clk[7],&LCD);
							flag=1;
							continue;
							}

								Clk[7]='0';
								Lcd_VoidGoXY(&LCD,0,7);
								Lcd_VoidSendNumForTimers(Clk[7],&LCD);
								Clk[6]++;
								Lcd_VoidGoXY(&LCD,0,6);
								Lcd_VoidSendNumForTimers(Clk[6],&LCD);
								continue;
					}  /*-----------------------------------------------MINUTS PART-----------------------------------------------------------*/
					if(Clk[3]<'6')
					{
						if(Clk[4]<'9')
							{
							Clk[6]='0';
							Lcd_VoidGoXY(&LCD,0,6);
							Lcd_VoidSendNumForTimers(Clk[6],&LCD);
							/////////////////////////////////////////////////////////////////////////
							Clk[4]++;
							Lcd_VoidGoXY(&LCD,0,4);
							Lcd_VoidSendNumForTimers(Clk[4],&LCD);
							continue;
							}
								Clk[4]='0';
								Lcd_VoidGoXY(&LCD,0,4);
								Lcd_VoidSendNumForTimers(Clk[4],&LCD);
								/////////////////////////////////////////////////////////////////////////////////////
								Clk[3]++;
								Lcd_VoidGoXY(&LCD,0,3);
								Lcd_VoidSendNumForTimers(Clk[3],&LCD);
								continue;
					}
				}
				while(0);
			}
}


/*ISR Implementation*/
void CLK1Sec(void)
{
	static u16 counter;
	counter++;
	if(counter==3907)
	{
		/*THE ACTION EVERY 1 SEC*/
		TOG_BIT(PORTB,PIN0);
		CLOCK_MODE();
	//	StopWatch ();
		counter=0;
	}
}

