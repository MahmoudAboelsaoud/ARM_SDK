/******************************************************/
/* Author      : Mahmoud Aboelsaoud                   */
/* Date        : 17 JAN 2020                          */
/* version     : V01                                  */
/* Descraption : SYSTICK code                         */
/******************************************************/

#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H

/* Struct of system time registers*/
#define    SYSTICK_BASE_ADDRESS   0xE000E010

typedef struct
{
  u32 STK_CTRL;     /*control and stutus register*/
  u32 STK_LOAD;     /*reload value register*/
  u32 STK_VAL;      /*current value register*/
  u32 STK_CALIB;    /*calibration value register*/
}SysTick_t;

/*  SysTick pointer to the struct of system time registers*/
#define  SysTick ( volatile SysTick_t* )(SYSTICK_BASE_ADDRESS)


/*STK_CTRL*/
#define  ENABLE      0
#define  TICKINT     1
#define  CLKSOURCE   2
#define  COUNTFLAG   16




#endif