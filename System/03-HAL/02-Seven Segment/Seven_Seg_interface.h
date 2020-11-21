/*********************************/
/* Author : Mahmoud Aboelsaoud   */
/* Date   : 24 oct 2020          */
/* Version: 01V                  */
/* Description : 7-segment driver*/
/*********************************/
/****************************************************************/
/* File Garud to make sure that the header file is not reapeted */
/****************************************************************/
#ifndef SEVEN_SEG_INTERFACE_H
#define SEVEN_SEG_INTERFACE_H

/* enum for the aviable 7-segment types*/
typedef enum
{
	COMMON_ANODE =0,
	COMMON_CATHOUD
}enum_SevSegType;

/* HAL_SevSegmentInit function uesed to init the 7-seg this function take copy_u8port port(A,B,C) and 
   copy_u8SevSegType the 7-seg type (Commen Anode ,Commen Cathod) and copy_u8ptrSevSegHandler is address
   of the Buffer where the 7-seg info stored it created by the user side */
bool_t HAL_SevSegmentInit(u8 copy_u8port, enum_SevSegType copy_u8SevSegType, u8* copy_u8ptrSevSegHandler);
/* HAL_SevSegmentDisplay function used to display an number on the seven segment this function take 
   copy_u8ptrSevSegHandler is the 7-segment number in the buffer whice content the data of each 7-seg*/
bool_t HAL_SevSegmentDisplay(u8 copy_u8ptrSevSegHandler ,u8 copy_u8DisplayNum);



#endif
