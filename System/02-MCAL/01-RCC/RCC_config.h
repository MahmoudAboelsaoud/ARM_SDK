/**********************************************************/
/* Author  : Mahmoud Aboelsaoud                           */
/* Version : V01                                          */
/* Date    : 26 sep 2020                                  */
/**********************************************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/* Options :               RCC_HSE_CRYSTAL
			   RCC_HSE_RC
			   RCC_HSI
			   RCC_PLL   
							*/
			   
#define RCC_CLOCK_TYPES  RCC_HSI

/* PLL options:
			  RCC_PLL_IN_HSI_DIV_2
			  RCC_PLL_IN_HSE_DIV_2
			  RCC_PLL_IN_HSE    */
			  
/* Note: Select value only if you input clock source is PLL */
#if RCC_CLOCK_TYPES == RCC_PLL
#define RCC_PLL_INPUT RCC_PLL_IN_HSI_DIV_2
#endif


/* PLL Multipxer value options 2 to 16 : */
#if RCC_CLOCK_TYPES == RCC_PLL
#define RCC_PLL_MUL_VAL    4
#endif




#endif
