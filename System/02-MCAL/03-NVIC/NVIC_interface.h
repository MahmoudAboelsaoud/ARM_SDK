/******************************************************/
/* Author      : Mahmoud Aboelsaoud                   */
/* Date        : 20 Nov 2020                          */
/* version     : V01                                  */
/* Descraption : NVIC Interfaces                            */
/******************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


bool_t MNVIC_boolEnableInterrupt(u8 copy_u8IntNumber);


bool_t MNVIC_boolDisableInterrupt(u8 copy_u8IntNumber);


bool_t MNVIC_boolSetPendingFlag(u8 copy_u8IntNumber);


bool_t MNVIC_boolClearPendingFlag(u8 copy_u8IntNumber);


bool_t MNVIC_boolGetActiveFlag(u8 copy_u8IntNumber, u8* copy_u8BitStatus);

#endif