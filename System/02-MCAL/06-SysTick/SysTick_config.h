/******************************************************/
/* Author      : Mahmoud Aboelsaoud                   */
/* Date        : 17 JAN 2021                          */
/* version     : V01                                  */
/* Descraption : SysTick Configuration                */
/******************************************************/
#ifndef SYSTICK_CONFIG_H
#define SYSTICK_CONFIG_H

/* SYSTIMER_MODE :-
				  MULTI_SHOT_TIMER
				  SINGLE_SHOT_TIMER*/
#define   SYSTIMER_MODE    MULTI_SHOT_TIMER

/* SYSTIMER_CLOCK_SOURCE :-
			              SYSTICK_SOURCE_AHB
						  SYSTICK_SOURCE_AHB/8*/
#define   SYSTIMER_CLOCK_SOURCE	  SYSTICK_SOURCE_AHB/8			  



#endif