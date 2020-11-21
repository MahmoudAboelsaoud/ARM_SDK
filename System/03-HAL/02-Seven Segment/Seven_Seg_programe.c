/*********************************/
/* Author : Mahmoud Aboelsaoud   */
/* Date   : 24 oct 2020          */
/* Version: 01V                  */
/* Description : 7-segment driver*/
/*********************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"


#include "Seven_seg_config.h"
#include "Seven_seg_interface.h"
#include "Seven_seg_private.h"

#include "DIO_private.h"
#include "DIO_interface.h"

static u8 SevSegHandlerNum = 0;

bool_t HAL_SevSegmentInit(u8 copy_u8port, enum_SevSegType copy_u8SevSegType, u8* copy_u8ptrSevSegHandler)
{
	bool_t ret_val = E_TRUE;
	if(copy_u8ptrSevSegHandler != NULL)
	{
		if(SevSegHandlerNum < MAX_NUMBER_OF_HANDLERS)
		{
		arr_SevSegInfo_buffer[SevSegHandlerNum].copySrt_u8port = copy_u8port;
		arr_SevSegInfo_buffer[SevSegHandlerNum].copyStr_u8SevSegType = copy_u8SevSegType;
		*copy_u8ptrSevSegHandler = SevSegHandlerNum;
		SevSegHandlerNum++;
		}
		else
		{
			ret_val = E_FALSE;
		}
	}
	else
	{
		ret_val = E_FALSE;
	}
	return ret_val;
}

bool_t HAL_SevSegmentDisplay(u8 copy_u8ptrSevSegHandler, u8 copy_u8DisplayNum)
{
	bool_t ret_val = E_TRUE;
	if( (copy_u8DisplayNum < 10) && (copy_u8ptrSevSegHandler <= MAX_NUMBER_OF_HANDLERS) )
	{
		if((arr_SevSegInfo_buffer[copy_u8ptrSevSegHandler].copyStr_u8SevSegType) == COMMON_CATHOUD)
		{
			switch(arr_SevSegInfo_buffer[copy_u8ptrSevSegHandler].copySrt_u8port)
			{
				case GPIOA : GPIOA_ODR = ~ pattern[copy_u8DisplayNum];break;
				case GPIOB : GPIOB_ODR = ~ pattern[copy_u8DisplayNum];break;
				case GPIOC : GPIOC_ODR = ~ pattern[copy_u8DisplayNum];break;
				default    : break;		
			}
			
		}
		else if((arr_SevSegInfo_buffer[copy_u8ptrSevSegHandler].copyStr_u8SevSegType) == COMMON_ANODE)
		{
			switch(arr_SevSegInfo_buffer[copy_u8ptrSevSegHandler].copySrt_u8port)
			{
				case GPIOA : GPIOA_ODR = pattern[copy_u8DisplayNum];break;
				case GPIOB : GPIOB_ODR = pattern[copy_u8DisplayNum];break;
				case GPIOC : GPIOC_ODR = pattern[copy_u8DisplayNum];break;
				default    : break;		
			}
			
			
		}
		else
		{
			ret_val = E_FALSE;
	    }
	}
	else
	{
		ret_val = E_FALSE;
	}
	return ret_val;
}
