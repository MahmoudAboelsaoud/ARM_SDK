/*********************************/
/* Author : Mahmoud Aboelsaoud   */
/* Date   : 24 oct 2020          */
/* Version: 01V                  */
/* Description : LED driver code */
/*********************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LED_interface.h"
#include "DIO_private.h"
#include "DIO_interface.h"

bool_t LED_voidLedON( u8 copy_u8port, u8 copy_u8PIN)
{
	bool_t ret_val = E_TRUE;
	if((copy_u8port >=0) && (copy_u8PIN >=0))
	{
		switch(copy_u8port)
		{     
				case GPIOA : SET_BIT(GPIOA_ODR, copy_u8PIN); break;
				case GPIOB : SET_BIT(GPIOB_ODR, copy_u8PIN); break;
				case GPIOC : SET_BIT(GPIOC_ODR, copy_u8PIN); break;
				default    : break;
		}
	}
	else
	{
		ret_val = E_false;
	}
}

bool_t LED_voidLedOFF( u8 copy_u8port, u8 copy_u8PIN)
{
	bool_t ret_val = E_TRUE;
	if((copy_u8port >=0) && (copy_u8PIN >=0))
	{
		switch(copy_u8port)
		{     
				case GPIOA : CLR_BIT(GPIOA_ODR, copy_u8PIN); break;
				case GPIOB : CLR_BIT(GPIOB_ODR, copy_u8PIN); break;
				case GPIOC : CLR_BIT(GPIOC_ODR, copy_u8PIN); break;
				default    : break;
		}
	}
	else
	{
		ret_val = E_false;
	}
}
	
bool_t LED_voidLedTogal( u8 copy_u8port, u8 copy_u8PIN)
{
	bool_t ret_val = E_TRUE;
	if((copy_u8port >=0) && (copy_u8PIN >=0))
	{
		switch(copy_u8port)
		{     
				case GPIOA : TOG_BIT(GPIOA_ODR, copy_u8PIN); break;
				case GPIOB : TOG_BIT(GPIOB_ODR, copy_u8PIN); break;
				case GPIOC : TOG_BIT(GPIOC_ODR, copy_u8PIN); break;
				default    : break;
		}
	}
	else
	{
		ret_val = E_false;
	}	
}
