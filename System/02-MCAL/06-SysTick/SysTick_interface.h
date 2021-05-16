/******************************************************/
/* Author      : Mahmoud Aboelsaoud                   */
/* Date        : 17 JAN 2020                          */
/* version     : V02                                  */
/* Descraption : SYSTICK code                         */
/******************************************************/

#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H


/*  MCAL_boolSysTickSetValue chearge the systick  load register with the value we want (STK_LOAD)*
bool_t MCAL_boolSysTickSetValue(u32 copy_u32loadValue);

/*  MCAL_boolSysTickStart  enable the systick and stertt count 
bool_t MCAL_boolSysTickStart();*/



/*  MSTK_boolInit init the system timer clock (AHB or AHB/8) */
bool_t MSTK_boolInit(void);
/* MSTK_boolSetBusyWait Asynchronous function set the load register with the coming value and polling on the count flag till 
   timer reach the zero value */
bool_t MSTK_boolSetBusyWait(u32 copy_u32Ticks);
/* MSTK_boolSetIntervalSingle  Synchronous function set the load register with the coming value and the callback is handled
   and return till the interrupt fire when the counter reach the zero value for only one time */ 
bool_t MSTK_boolSetIntervalSingle(u32 copy_u32Ticks ,void (*copy_ptr)(void));
/* MSTK_boolSetIntervalSingle  Synchronous function set the load register with the coming value and the callback is handled
   and return till the interrupt fire when the counter reach the zero value for more than one time */ 
bool_t MSTK_boolSetIntervalPeriodic(u32 copy_u32Ticks ,void (*copy_ptr)(void) );
/* MSTK_boolStopInterval stop the timer */
bool_t MSTK_boolStopInterval(void);
/* MSTK_u32GetElapsedTime return the current timer value */
u32    MSTK_u32GetElapsedTime(void);
/* MSTK_u32GetRemainingTime return the value till the interrupt fire and the timer reach the zeri value */
u32    MSTK_u32GetRemainingTime(void);






#endif