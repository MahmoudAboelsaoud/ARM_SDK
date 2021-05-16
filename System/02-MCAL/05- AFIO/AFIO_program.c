/******************************************************/
/* Author      : Mahmoud Aboelsaoud                   */
/* Date        : 18 DCE 2020                          */
/* version     : V01                                  */
/* Descraption : AFIO code                            */
/******************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"

bool_t MAFIO_boolSetEXTIConfigartion(u8 copy_u8Line, u8 copy_u8PortMap)
{
	bool_t ret_val = E_TRUE;
	u8 local_u8RegisterIndex =0;
	if(copy_u8Line <=  3)
	{
		local_u8RegisterIndex =0;
	}	
	else if(copy_u8Line <=  7)
	{
		local_u8RegisterIndex =1;
		copy_u8Line  -= 4;
	}
	else if(copy_u8Line <= 11)
	{
		local_u8RegisterIndex =2;
		copy_u8Line -=8;
	}
	else if(copy_u8Line <= 15)
	{
		local_u8RegisterIndex =3;
		copy_u8Line -=12;
	}
	else
	{
		 ret_val = E_FALSE;
	}
	/* set the register value and then write in it */
	AFIO->EXTICR[local_u8RegisterIndex] &=~ (0b1111 << (copy_u8Line *4));
	AFIO->EXTICR[local_u8RegisterIndex] |= (copy_u8PortMap << (copy_u8Line *4));

	return ret_val;
}
