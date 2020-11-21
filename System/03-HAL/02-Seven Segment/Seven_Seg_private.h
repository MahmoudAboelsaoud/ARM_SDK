/*********************************/
/* Author : Mahmoud Aboelsaoud   */
/* Date   : 24 oct 2020          */
/* Version: 01V                  */
/* Description : 7-segment driver*/
/*********************************/
/****************************************************************/
/* File Garud to make sure that the header file is not reapeted */
/****************************************************************/
#ifndef SEVEN_SEG_PRIVATE_H
#define SEVEN_SEG_PRIVATE_H

typedef struct 
{
	u8 copySrt_u8port;
	enum_SevSegType copyStr_u8SevSegType;
}str_SevSegInfo_t;

str_SevSegInfo_t arr_SevSegInfo_buffer[MAX_NUMBER_OF_HANDLERS];

const u8 pattern[]= {0b0111111,0b0110000, 0b1011011,0b1001111,0b1100110,0b1101101,0b1111101,0b0000111,0b1111111,0b1101111};



#endif
