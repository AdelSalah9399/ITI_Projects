/*
 * DIO_program.c
 *
 *  Created on: Mar 22, 2023
 *      Author: Adel
 */

#include "DIO_Interface.h"



ErrState DIO_ErrStateSetPinDirection(Groub_Num GroupNum ,Pins_Num PinNum ,DDR_Types Direction)	//config DDR
{
	if ((PinNum>=PIN0) && (PinNum<=PIN7))
	{	/*---------make the pin INPUT /DDR=0/CLR_BIT------*/
		if(Direction == INPUT)
		{
			switch(GroupNum)
			{
			case Groub_A  :  CLR_BIT(DDRA,PinNum) ; break;
			case Groub_B  :  CLR_BIT(DDRB,PinNum) ; break;
			case Groub_C  :  CLR_BIT(DDRC,PinNum) ; break;
			case Groub_D  :  CLR_BIT(DDRD,PinNum) ; break;
			default : return GroubErr;
			}
		}
		/*---------make the pin OUTPUT /DDR=1/CLR_BIT------*/
		else if (Direction == OUTPUT)
		{
			switch(GroupNum)
			{
			case Groub_A  :  SET_BIT(DDRA,PinNum) ; break;
			case Groub_B  :  SET_BIT(DDRB,PinNum) ; break;
			case Groub_C  :  SET_BIT(DDRC,PinNum) ; break;
			case Groub_D  :  SET_BIT(DDRD,PinNum) ; break;
			default : return GroubErr;
			}
		}
		else
		{
			return DirectionErr;
		}
		return NoErr;
	}
	else
	{
		return PinNumErr;
	}
}
ErrState DIO_ErrStateSetPinValue(Groub_Num GroupNum ,Pins_Num PinNum ,PIN_STATE ValueState)		//write on pin
{

	if ((PinNum>=PIN0) && (PinNum<=PIN7))
	{	/*---------WRITE ZERO ON /PORT/BIT AS OUTPUT -----------*/
		if(ValueState == DIO_HIGH)
		{
			switch(GroupNum)
			{
			case Groub_A  :  CLR_BIT(PORTA,PinNum) ; break;
			case Groub_B  :  CLR_BIT(PORTB,PinNum) ; break;
			case Groub_C  :  CLR_BIT(PORTC,PinNum) ; break;
			case Groub_D  :  CLR_BIT(PORTD,PinNum) ; break;
			default : return GroubErr;
			}
		}
		/*---------WRITE ONE ON /PORT/BIT AS OUTPUT------------*/
		else if (ValueState == DIO_LOW)
		{
			switch(GroupNum)
			{
			case Groub_A  :  SET_BIT(PORTA,PinNum) ; break;
			case Groub_B  :  SET_BIT(PORTB,PinNum) ; break;
			case Groub_C  :  SET_BIT(PORTC,PinNum) ; break;
			case Groub_D  :  SET_BIT(PORTD,PinNum) ; break;
			default : return GroubErr;
			}
		}
		else
		{
			return ValueErr;
		}
		return NoErr;
	}
	else
	{
		return PinNumErr;
	}

}
ErrState DIO_ErrStateReadPinValue(Groub_Num GroupNum ,Pins_Num PinNum ,u8* Result)		        //read from pin
{
	if((PinNum>=PIN0)&&(PinNum<=PIN7))
	{
		switch(GroupNum)
		{
		case Groub_A  : *Result=GET_BIT(PINA,PinNum); break;
		case Groub_B  : *Result=GET_BIT(PINB,PinNum); break;
		case Groub_C  : *Result=GET_BIT(PINC,PinNum); break;
		case Groub_D  : *Result=GET_BIT(PIND,PinNum); break;
		default  : return GroubErr; break;
		}
		return NoErr;
	}
	else
	{
		return PinNumErr;
	}
}

ErrState DIO_ErrStateSetGroubDirection(Groub_Num GroupNum ,DDR_Types Direction)			    	//config all groub DDR
{
	if((Direction>=MIN_RANG) && (Direction<=MAX_RANG))
	{
		switch(GroupNum)
		{
		case Groub_A : DDRA = Direction; break;
		case Groub_B : DDRB = Direction; break;
		case Groub_C : DDRC = Direction; break;
		case Groub_D : DDRD = Direction; break;
		default : return GroubErr ;
		}
		return NoErr;
	}
	else
	{
		return DirectionErr;
	}
}
ErrState DIO_ErrStateSetGroubValue(Groub_Num GroupNum ,u8 ValueState)								//write on all groub
{
	if((ValueState>=MIN_RANG) && (ValueState<=MAX_RANG))
		{
			switch(GroupNum)
			{
			case Groub_A : PORTA = ValueState; break;
			case Groub_B : PORTB = ValueState; break;
			case Groub_C : PORTC = ValueState; break;
			case Groub_D : PORTD = ValueState; break;
			default : return GroubErr ;
			}
			return NoErr;
		}
		else
		{
			return ValueErr;
		}
	}
ErrState DIO_ErrStateReadGroubValue(Groub_Num GroupNum ,u8* Result)	 				    		//read from all groub
{
	if(1/*address_condition*/)
	{
		switch(GroupNum)
		{
		 case 0 : *Result=PINA; break;
		 case 1 : *Result=PINA; break;
		 case 2 : *Result=PINA; break;
		 case 3 : *Result=PINA; break;
		 default : return GroubErr; break;
		}
		return NoErr;
	}
	else
	{
		return AddressErr;
	}
}


