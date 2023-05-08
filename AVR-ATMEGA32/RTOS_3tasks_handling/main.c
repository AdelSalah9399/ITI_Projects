/*
 * main.c
 *
 *  Created on: Apr 17, 2023
 *      Author: Adel
 */


void LED1 (void);
void LED2 (void);
void LED3 (void);

void main()
{
	DIO_ErrStateSetPinDirection(Groub_B,PIN0,DIO_OUTPUT);
	DIO_ErrStateSetPinDirection(Groub_B,PIN1,DIO_OUTPUT);
	DIO_ErrStateSetPinDirection(Groub_B,PIN2,DIO_OUTPUT);

	RTOS_CreatTask(0,100,&LED1);
	RTOS_CreatTask(1,200,&LED2);
	RTOS_CreatTask(2,400,&LED3);

	RTOS_Start();
	while(1);
}

void LED1 (void)
{
	static u8 local_led=0;
	TOG_BIT(local_led,0);
	DIO_ErrStateSetPinValue(Groub_B,PIN0,local_led);
}

void LED2 (void)
{

	static u8 local_led=0;
	TOG_BIT(local_led,0);
	DIO_ErrStateSetPinValue(Groub_B,PIN1,local_led);
}

void LED3 (void)
{
	static u8 local_led=0;
	TOG_BIT(local_led,0);
	DIO_ErrStateSetPinValue(Groub_B,PIN2,local_led);
}

