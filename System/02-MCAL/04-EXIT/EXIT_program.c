/******************************************************/
/* Author      : Mahmoud Aboelsaoud                   */
/* Date        : 17 DCE 2020                          */
/* version     : V01                                  */
/* Descraption : EXIT code                            */
/******************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXIT_interface.h"
#include "EXIT_config.h"
#include "EXIT_private.h"
/* globle var pointer to function */
static void (*EXIT_cb) (void) = NULL;

void EXTI0_IRQHandler(void)
{
 EXIT_cb();
 /*  clear the pending bit */
 SET_BIT( EXTI->PR, 0);
}

bool_t MEXTI_boolInit()
{
	bool_t ret_val = E_TRUE;
	#if   EXTI_MODE == RISSING
		SET_BIT( EXTI->RTSR, EXTI_LINE);
	#elif EXTI_MODE == FALLING
		SET_BIT( EXTI->FTSR, EXTI_LINE);
	#elif EXTI_MODE == ON_CHANGE
		SET_BIT( EXTI->RTSR, EXTI_LINE);
		SET_BIT( EXTI->FTSR, EXTI_LINE);
	#else #error (" Wrong Sence Mode !")
	#endif
	/*to make sure that the interrupt is disable at the initalization*/
	CLR_BIT( EXTI->IMR, EXTI_LINE);
	return ret_val;
}
/*Enable the line LINE0 (A0 B0 C0)*/
bool_t MEXTI_boolEnableEXTI(u8 copy_u8Line)
{
	bool_t ret_val = E_TRUE;
	SET_BIT( EXTI->IMR, copy_u8Line);
	return ret_val;
}
/*Disable the line LINE0 (A0 B0 C0)*/
bool_t MEXTI_boolDisableEXTI(u8 copy_u8Line)
{
	bool_t ret_val = E_TRUE;
	CLR_BIT( EXTI->IMR, copy_u8Line);
	return ret_val;
}

bool_t MEXTI_boolSwTrigger(u8 copy_u8Line)
{
	bool_t ret_val = E_TRUE;
	SET_BIT( EXTI->SWIER, copy_u8Line);
	return ret_val;
}

bool_t MEXTI_boolSetSignalLatch(u8 copy_u8Line, u8 copy_u8Mode)
{
	bool_t ret_val = E_TRUE;
	switch(copy_u8Mode)
	{
		case RISSING  : SET_BIT( EXTI->RTSR, copy_u8Line); break;
		case FALLING  : SET_BIT( EXTI->FTSR, copy_u8Line); break;
		case ON_CHANGE:{SET_BIT( EXTI->RTSR, copy_u8Line);
						SET_BIT( EXTI->FTSR, copy_u8Line);break;}
		default       :									  break;


	}
	return ret_val;	
}

bool_t MEXTI_boolSetCallBack(void (*ptr_cb)(void)
{
	bool_t ret_val = E_TRUE;
	EXIT_cb = ptr_cb;
	return ret_val;
}