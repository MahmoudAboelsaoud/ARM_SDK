/*********************************/
/* Author : Mahmoud Aboelsaoud   */
/* Date   : 24 oct 2020          */
/* Version: 01V                  */
/* Description : LED driver  APIS*/
/*********************************/
/****************************************************************/
/* File Garud to make sure that the header file is not reapeted */
/****************************************************************/
#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H


bool_t LED_voidLedON( u8 copy_u8port, u8 copy_u8PIN);
bool_t LED_voidLedOFF( u8 copy_u8port, u8 copy_u8PIN);
bool_t LED_voidLedTogal( u8 copy_u8port, u8 copy_u8PIN);




#endif
