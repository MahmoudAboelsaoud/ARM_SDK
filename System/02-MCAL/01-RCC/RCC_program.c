/**********************************************************/
/* Author  : Mahmoud Aboelsaoud                           */
/* Version : V01                                          */
/* Date    : 26 sep 2020                                  */
/**********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if(Copy_u8PerId <=31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB   : SET_BIT(RCC_AHBENB  ,Copy_u8PerId); break;
			case RCC_APB1  : SET_BIT(RCC_APB1ENB ,Copy_u8PerId); break;
			case RCC_APB2  : SET_BIT(RCC_APB2ENB ,Copy_u8PerId); break;
		  //default        : /* Return Error*/                   break;
		}
		
	}
	else
	{
		/*return error*/
	}
}


void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if(Copy_u8PerId <=31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB   : CLR_BIT(RCC_AHBENB  ,Copy_u8PerId); break;
			case RCC_APB1  : CLR_BIT(RCC_APB1ENB ,Copy_u8PerId); break;
			case RCC_APB2  : CLR_BIT(RCC_APB2ENB ,Copy_u8PerId); break;
		  //default        : /* Return Error*/                   break;
		}
		
	}
	else
	{
		/*return error*/
	}
}


void RCC_voidInitSysClock(void)
{
	#if           RCC_CLOCK_TYPES == RCC_HSE_CRYSTAL
				  RCC_CR   = 0x00010000;  /*  Enable the HSE and no bypassas we use the crystal */  
				  RCC_CFGR = 0x00000001;
				  
	#elif         RCC_CLOCK_TYPES==RCC_HSE_RC
				  RCC_CR   = 0x00050000;  /*  Enable the HSE and bypass as we need only one pin for connect the RC */
				  RCC_CFGR = 0x00000001;
				   
	#elif         RCC_CLOCK_TYPES==RCC_HSI
				  RCC_CR   = 0x00000001;   /* Enable HSI and no trimining */
				  RCC_CFGR = 0x00000000;
				  
	#elif	      RCC_CLOCK_TYPES == RCC_PLL
				  RCC_CFGR|= (RCC_PLL_MUL_VAL << 18); /* set the MUL factor 4:16*/
	
		#if     RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
				  RCC_CFGR = 0x00000002; /* PLL Source is HSI Div 2*/
				  
		#elif   RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
				  RCC_CFGR = 0x00030002; /* PLL Source is HSE Div 2*/
		
		#elif   RCC_PLL_INPUT == RCC_PLL_IN_HSE
		                  RCC_CFGR = 0x00010002; /* PLL Source is HSE */
                        RCC_CR   = 0x01000000;   /* PLL is Enable as it must config PLL futers then enable the PLL */
		
		#endif
	#else
		#error("erro selection")
	#endif
}
