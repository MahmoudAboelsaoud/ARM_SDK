/**********************************************************/
/* Author  : Mahmoud Aboelsaoud                           */
/* Version : V01                                          */
/* Date    : 26 sep 2020                                  */
/**********************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


/* Register Definiation */
/************clock on the prcessor**************/
#define RCC_CR                *((u32*)0x40021000)
#define RCC_CFGR              *((u32*)0x40021004)
/***********************************************/
#define RCC_CIR               *((u32*)0x40021008)
#define RCC_APB2RSTR          *((u32*)0x4002100C)
#define RCC_APB1RSTR          *((u32*)0x40021010)
/* clock enable and disable on the peripherals */
#define RCC_AHBENR            *((u32*)0x40021014)
#define RCC_APB2ENR           *((u32*)0x40021018)
#define RCC_APB1ENR           *((u32*)0x4002101C)
/***********************************************/
#define RCC_BDCR              *((u32*)0x40021020)
#define RCC_CSR               *((u32*)0x40021024)


/* Clock Types */
#define            RCC_HSE_CRYSTAL         0
#define 	       RCC_HSE_RC              1
#define		       RCC_HSI                 2
#define		       RCC_PLL                 3



/* PLL Types */
#define                 RCC_PLL_IN_HSI_DIV_2    0
#define			        RCC_PLL_IN_HSE_DIV_2    1
#define			        RCC_PLL_IN_HSE          2



/* BITs */
#define BIT0    0 
#define BIT1    1
#define BIT2    2
#define BIT3    3
#define BIT4    4
#define BIT5    5
#define BIT6    6
#define BIT7    7
#define BIT8    8
#define BIT9    9
#define BIT10  10
#define BIT11  11
#define BIT12  12
#define BIT13  13
#define BIT14  14
#define BIT15  15
#define BIT16  16
#define BIT17  17
#define BIT18  18
#define BIT19  19
#define BIT20  20
#define BIT21  21
#define BIT22  22
#define BIT23  23
#define BIT24  24
#define BIT25  25
#define BIT26  26
#define BIT27  27
#define BIT28  28
#define BIT29  29
#define BIT30  30
#define BIT31  31



#endif
