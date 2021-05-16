/******************************************************/
/* Author      : Mahmoud Aboelsaoud                   */
/* Date        : 17 DCE 2020                          */
/* version     : V01                                  */
/* Descraption : EXIT REDISTERS                       */
/******************************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H


/*External interrupt registers*/
typedef struct
{
	volatile u32 IMR;   /*interrupt mask register (active the line for the EXIT you need)*/
	volatile u32 EMR;   /*event mask register */
	volatile u32 RTSR;  /*raisng triager stutes register */
	volatile u32 FTSR;  /*failing triager stutes register */
	volatile u32 SWIER; /*software interrupt enable register*/
	volatile su32 PR;   /*pending register */
}EXTI_t;
/* pointer to the struct of External interrupt registers*/
#define   EXTI    ((volatile EXTI_t *)0x40010400)

#define   LINE0   	   0 /*A0 B0 C0 */
#define   LINE1        1 /*A1 B1 C1 */
#define   LINE2        2 /*A2 B2 C2 */
#define   LINE3        3
#define   LINE4        4
#define   LINE5        5
#define   LINE6        6
#define   LINE7        7


#define   RISSING       1
#define   FALLING       3
#define   ON_CHANGE     5

#endif
