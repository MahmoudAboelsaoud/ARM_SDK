/***********************************************/
/* Auther     : Mahmoud Aboelsaoud             */
/* Date       : 23 sep 2020                    */
/* Version    : V01                            */
/*Description : GPIO function imp              */
/***********************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

bool_t GPIO_voidSetPinDirection(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Mode)
{
	bool_t ret_val = E_TRUE;
	if(/*(copy_u8PORT >= 0) && (copy_u8PIN <= 15)*/ 1)
	{
		switch(copy_u8PORT)
		{
			case GPIOA :
						{
							if(copy_u8PIN <= 7)
							{
								GPIOA_CRL &=~((0b1111)<<(4*copy_u8PIN));
								GPIOA_CRL |=((copy_u8Mode)<<(4*copy_u8PIN));
							}
							else if(copy_u8PIN <= 15)
							{
								copy_u8PIN -=8; /*to reach the right pin exp: 9 ,9-8=1, 1*4=4 */
								GPIOA_CRH &=~((0b1111)<<(4*copy_u8PIN));
								GPIOA_CRH |=((copy_u8Mode)<<(4*copy_u8PIN));
							}
							break;
						}
			case GPIOB :
						{
							if(copy_u8PIN <= 7)
							{
								GPIOB_CRL &=~((0b1111)<<(4*copy_u8PIN));
								GPIOB_CRL |=((copy_u8Mode)<<(4*copy_u8PIN));
							}
							else if(copy_u8PIN <= 15)
							{
								copy_u8PIN -=8;
								GPIOB_CRH &=~((0b1111)<<(4*copy_u8PIN));
								GPIOB_CRH |=((copy_u8Mode)<<(4*copy_u8PIN));
							}
							break;
						}
			case GPIOC :
						{
							if(copy_u8PIN <= 7)
							{
								GPIOC_CRL &=~((0b1111)<<(4*copy_u8PIN));
								GPIOC_CRL |=((copy_u8Mode)<<(4*copy_u8PIN));
							}
							else if(copy_u8PIN <= 15)
							{
								copy_u8PIN -=8;
								GPIOC_CRH &=~((0b1111)<<(4*copy_u8PIN));
								GPIOC_CRH |=((copy_u8Mode)<<(4*copy_u8PIN));
							}
							break;
						}
			default    :  ret_val = E_FALSE;  break;
			
		}
	}
	else
	{
		ret_val = E_FALSE;
	}
	
	return ret_val;
}


bool_t GPIO_u8SetPinValue(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8value)
{
	bool_t ret_val = E_TRUE;
	if(/*(copy_u8PORT >= 0) && (copy_u8PIN <= 15)*/ 1)
	{
		switch(copy_u8PORT)
		{
			case GPIOA :
						{
						 if(copy_u8value == GPIO_HIGH)
						 {
							 SET_BIT(GPIOA_ODR, copy_u8PIN);
						 }
						 else if(copy_u8value == GPIO_LOW)
						 {
							 CLR_BIT(GPIOA_ODR, copy_u8PIN);
						 }
							break;
						}
			case GPIOB :
						{
						 if(copy_u8value == GPIO_HIGH)
						 {
							 SET_BIT(GPIOB_ODR, copy_u8PIN);
						 }
						 else if(copy_u8value == GPIO_LOW)
						 {
							 CLR_BIT(GPIOB_ODR, copy_u8PIN);
						 }
							break;
						}
			case GPIOC :
						{
						 if(copy_u8value == GPIO_HIGH)
						 {
							 SET_BIT(GPIOC_ODR, copy_u8PIN);
						 }
						 else if(copy_u8value == GPIO_LOW)
						 {
							 CLR_BIT(GPIOC_ODR, copy_u8PIN);
						 }
							break;
						}
			default    : ret_val = E_FALSE; break;
			
		}
	}
	else
	{
		ret_val = E_FALSE;
	}
	
	return ret_val;	
}

bool_t GPIO_u8WriteValue(u8 copy_u8PORT, u8 copy_u8value)
{
	bool_t ret_val = E_TRUE;
	if((/*(copy_u8PORT >= 0) && (copy_u8PIN <= 15)*/ 1))
	{
		switch(copy_u8PORT)
		{
			case GPIOA : GPIOA_ODR = copy_u8value; break;
			case GPIOB : GPIOB_ODR = copy_u8value; break;
			case GPIOC : GPIOC_ODR = copy_u8value; break;
			default    :  break;
		}
	}
	else
	{
		ret_val = E_FALSE;
	}
	return ret_val;
}

u8 GPIO_u8GetPinValue(u8 copy_u8PORT, u8 copy_u8PIN)
{
	u8 ret_val=0;
	switch(copy_u8PORT)
		{
			case GPIOA : ret_val= GET_BIT(GPIOA_IDR, copy_u8PIN); break;
			case GPIOB : ret_val= GET_BIT(GPIOB_IDR, copy_u8PIN); break;
			case GPIOC : ret_val= GET_BIT(GPIOC_IDR, copy_u8PIN); break;
			default    :  										  break;
		}
	return ret_val;
}


#ifdef SPEED_UP_SET_RESET_OPERTION

bool_t GPIO_u8SpeedSetPinValue(u8 copy_u8PORT, u8 copyPIN)
{
bool_t ret_val = E_TRUE;
	if(/*(copy_u8PORT >= 0) && (copy_u8PIN <= 15)*/1)
	{
		switch(copy_u8PORT)
		{
			case GPIOA :  GPIOA_BSR = (1<<copyPIN); break;
			case GPIOB :  GPIOB_BSR = (1<<copyPIN); break;
			case GPIOC :  GPIOC_BSR = (1<<copyPIN); break;
			default    :                            break;
			
		}
		
	}
	else
	{
		ret_val = E_FALSE;
	}
	return ret_val;
}
	
bool_t GPIO_u8SpeedClearPinValue(u8 copy_u8PORT, u8 copyPIN)
{
bool_t ret_val = E_TRUE;
	if(/*(copy_u8PORT >= 0) && (copy_u8PIN <= 15)*/1)
	{
		switch(copy_u8PORT)
		{
			case GPIOA :  GPIOA_BRR = (1<<copyPIN); break;
			case GPIOB :  GPIOB_BRR = (1<<copyPIN); break;
			case GPIOC :  GPIOC_BRR = (1<<copyPIN); break;
			default    :                            break;
			
		}
		
	}
	else
	{
		ret_val = E_FALSE;
	}
	return ret_val;
}


#endif


bool_t GPIO_u8LockPinConfig(u8 copy_u8PORT, u8 copy_u8PIN)
{
	bool_t ret_val = E_TRUE;
	if(/*(copy_u8PORT >= 0) && (copy_u8PIN <= 15)*/ 1)
	{
		switch(copy_u8PORT)
		{
			case GPIOA :  SET_BIT(GPIOA_LCK, copy_u8PIN); break;
			case GPIOB :  SET_BIT(GPIOB_LCK, copy_u8PIN); break;
			case GPIOC :  SET_BIT(GPIOC_LCK, copy_u8PIN); break;
			default    :                                  break;
			
		}
		
	}
	else
	{
		ret_val = E_FALSE;
	}
	return ret_val;
}
