/******************************************************/
/* Author      : Mahmoud Aboelsaoud                   */
/* Date        : 20 Nov 2020                          */
/* version     : V01                                  */
/* Descraption : NVIC code                            */
/******************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

bool_t MNVIC_boolEnableInterrupt(u8 copy_u8IntNumber)
{
	bool_t ret_val = E_TRUE;
	if(copy_u8IntNumber <= 31)
	{	
		/* Enable The Interrupts In The NVIC from 0 to 31*/
		NVIC_ISER0 = (1 << copy_u8IntNumber);
	}
	else if(copy_u8IntNumber <= 59)
	{
	 	/* Enable The Interrupts In The NVIC from 32 to 59*/
		copy_u8IntNumber -=32;
		NVIC_ISER1 = (1 << copy_u8IntNumber);
	}
	else
	{
		ret_val = E_FALSE;
	}
	return ret_val; 
}


bool_t MNVIC_boolDisableInterrupt(u8 copy_u8IntNumber)
{
	bool_t ret_val = E_TRUE;
	if(copy_u8IntNumber <= 31)
	{	
		/* Disable The Interrupts In The NVIC from 0 to 31*/
		NVIC_ICER0 = (1 << copy_u8IntNumber);
	}
	else if(copy_u8IntNumber <= 59)
	{
	 	/* Disable The Interrupts In The NVIC from 32 to 59*/
		copy_u8IntNumber -=32;
		NVIC_ICER1 = (1 << copy_u8IntNumber);
	}
	else
	{
		ret_val = E_FALSE;
	}
	return ret_val; 
}

bool_t MNVIC_boolSetPendingFlag(u8 copy_u8IntNumber)
{
	bool_t ret_val = E_TRUE;
	if(copy_u8IntNumber <= 31)
	{	
		/* Disable The Interrupts In The NVIC from 0 to 31*/
		NVIC_ISPR0 = (1 << copy_u8IntNumber);
	}
	else if(copy_u8IntNumber <= 59)
	{
	 	/* Disable The Interrupts In The NVIC from 32 to 59*/
		copy_u8IntNumber -=32;
		NVIC_ISPR1 = (1 << copy_u8IntNumber);
	}
	else
	{
		ret_val = E_FALSE;
	}
	return ret_val; 
}

bool_t MNVIC_boolClearPendingFlag(u8 copy_u8IntNumber)
{
	bool_t ret_val = E_TRUE;
	if(copy_u8IntNumber <= 31)
	{	
		/* Disable The Interrupts In The NVIC from 0 to 31*/
		NVIC_ICPR0 = (1 << copy_u8IntNumber);
	}
	else if(copy_u8IntNumber <= 59)
	{
	 	/* Disable The Interrupts In The NVIC from 32 to 59*/
		copy_u8IntNumber -=32;
		NVIC_ICPR1 = (1 << copy_u8IntNumber);
	}
	else
	{
		ret_val = E_FALSE;
	}
	return ret_val; 
}

bool_t MNVIC_boolGetActiveFlag(u8 copy_u8IntNumber, u8* copy_u8BitStatus)
{
	bool_t ret_val = E_TRUE;
	if( (copy_u8BitStatus!= NULL)&& (copy_u8IntNumber <= 31))
	{	
		*copy_u8BitStatus = GET_BIT(NVIC_IABR0, copy_u8IntNumber);
	}
	else if(copy_u8IntNumber <= 59)
	{
		 copy_u8IntNumber -=32;
		*copy_u8BitStatus = GET_BIT(NVIC_IABR1, copy_u8IntNumber);
	}
	else
	{
		ret_val = E_FALSE;
	}
	return ret_val; 
}



