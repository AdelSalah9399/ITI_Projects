/*
 * DIO_Interface.h
 *
 *  Created on: Mar 22, 2023
 *      Author: Adel
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

#include "../../common/STD_TYPE.h"
#include "../../common/BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_private.h"


ErrState DIO_ErrStateSetPinDirection(Groub_Num GroupNum ,Pins_Num PinNum ,DDR_Types Direction);  	//config DDR
ErrState DIO_ErrStateSetPinValue(Groub_Num GroupNum ,Pins_Num PinNum ,PIN_STATE ValueState);		//write on pin
ErrState DIO_ErrStateReadPinValue(Groub_Num GroupNum ,Pins_Num PinNum ,u8* Result);		            //read from pin

ErrState DIO_ErrStateSetGroubDirection(Groub_Num GroupNum ,DDR_Types Direction);			    	//config all groub DDR
ErrState DIO_ErrStateSetGroubValue(Groub_Num GroupNum ,u8 ValueState);								//write on all groub
ErrState DIO_ErrStateReadGroubValue(Groub_Num GroupNum ,u8* Result);	 				    		//read from all groub

#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
