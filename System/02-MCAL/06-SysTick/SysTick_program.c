/******************************************************/
/* Author      : Mahmoud Aboelsaoud                   */
/* Date        : 17 JAN 2020                          */
/* version     : V02                                  */
/* Descraption : SYSTICK code                         */
/******************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "SYSTICK_config.h"
#include "SYSTICK_private.h"
#include "SYSTICK_interface.h"

/* the callback function*/
void (*STK_callback)(void);
/* flag to idenfiy the single interval*/
static u8 interval_flag =0;
/*the systick Handler */
void SysTick_IRQHandler(void)
{
	STK_callback(void);
	if(interval_flag)
	{
		/* to stop the timer to count again*/
		SysTick->STK_LOAD = 0;
		/* stop the systick*/
		CLK_BIT(SysTick->STK_CTRL, ENABLE);	
	}
}


bool_t MSTK_boolInit(void)
{
	bool_t ret_val = E_TRUE;
	/* set the systm timer clock source like (AHB or AHB/8)*/
	#if (SYSTIMER_CLOCK_SOURCE == SYSTICK_SOURCE_AHB)
		SET_BIT(SysTick->STK_CTRL, CLKSOURCE);
	#elif (SYSTIMER_CLOCK_SOURCE == SYSTICK_SOURCE_AHB/8)
		CLK_BIT(SysTick->STK_CTRL, CLKSOURCE);
	#else
		ret_val = E_FALSE;
	#endif
	 /* DISable the sysTick ENABLE and the Interrupt*/
	 CLK_BIT(SysTick->STK_CTRL, TICKINT);
	 CLK_BIT(SysTick->STK_CTRL, ENABLE);
	return ret_val;
}

/*
bool_t MCAL_boolSysTickSetValue(u32 copy_u32loadValue)
{
	bool_t ret_val = E_TRUE;
	/* load the value to the STK_LOAD 
	SysTick->STK_LOAD = copy_u32loadValue ;
	
	return ret_val;
}



bool_t MCAL_boolSysTickStart()
{
	bool_t ret_val = E_TRUE;
	/* enable the systick than the systick is start count down until reach the zero 
	  then the count flag is one and the interrupt is fire
	SET_BIT(SysTick->STK_CTRL, ENABLE);
	
	return ret_val;
}
*/



bool_t MSTK_boolSetBusyWait(u32 copy_u32Ticks)
{
	bool_t ret_val = E_TRUE;
	/* load the value to the STK_LOAD */
	SysTick->STK_LOAD = copy_u32Ticks;
	/* Enable the system timer */
	SET_BIT(SysTick->STK_CTRL ,ENABLE);
	/* Polling on the COUNTFLAG until the timer reach the zero value */
	while(GET_BIT(SysTick->STK_CTRL ,COUNTFLAG) == 0);
	/* to stop the timer to count again*/
	SysTick->STK_LOAD = 0;
	
	return ret_val;
}


bool_t MSTK_boolSetIntervalSingle(u32 copy_u32Ticks ,void (*copy_ptr)(void))
{
	bool_t ret_val = E_TRUE;
	if(copy_ptr != NULL)
	{
		/*reset the clock at start*/
		CLK_BIT(SysTick->STK_CTRL ,ENABLE);
		SysTick->STK_VAL =0;
		/* Enable the system timer */
	    SET_BIT(SysTick->STK_CTRL ,ENABLE);
		/* set the interval flag */
		interval_flag =1;
		/* set the callback function */
		STK_callback  = copy_ptr;
		/* load the value to the STK_LOAD */
	    SysTick->STK_LOAD = copy_u32Ticks;
		/* Enable the interrupt */
		SET_BIT(SysTick->STK_CTRL, TICKINT);
	}
	else
	{
		ret_val = E_FALSE; 
	}

	return ret_val;
}


bool_t MSTK_boolSetIntervalPeriodic(u32 copy_u32Ticks ,void (*copy_ptr)(void) )
{
	bool_t ret_val = E_TRUE;
	if(copy_ptr != NULL)
	{
		/* set the callback function */
		STK_callback  = copy_ptr;
		/* load the value to the STK_LOAD */
	    SysTick->STK_LOAD = copy_u32Ticks;
		/* Enable the interrupt */
		SET_BIT(SysTick->STK_CTRL, TICKINT);
	}
	else
	{
		ret_val = E_FALSE; 
	}
	return ret_val;
}



bool_t MSTK_boolStopInterval(void)
{
	bool_t ret_val = E_TRUE;
	
	/* Stop the timer to count again*/
	SysTick->STK_LOAD = 0;
	/* DISable the systick*/
	CLK_BIT(SysTick->STK_CTRL, ENABLE);
	
	return ret_val;
}

u32  MSTK_u32GetElapsedTime(void)
{
	return ( SysTick->STK_VAL );
}


u32  MSTK_u32GetRemainingTime(void)
{
	return ( SysTick->STK_LOAD  - SysTick->STK_VAL );
}

