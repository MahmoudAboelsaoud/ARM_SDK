/******************************************************/
/* Author      : Mahmoud Aboelsaoud                   */
/* Date        : 18 DCE 2020                          */
/* version     : V01                                  */
/* Descraption : AFIO code                            */
/******************************************************/


#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H
/* MAFIO_boolSetEXTIConfigartion this function is used to select the external interrupt line and the pin we need to ues in the AF mode
   as EXTI pin the function take copy_u8Line is the line number (LINE0,LINE1,LINE2,...) and copy_u8PortMap is port map to active the pin 
   of the line number in this port (0b0000 for portA ,0b0010 for portB ,0b0011 for portC )*/
bool_t MAFIO_boolSetEXTIConfigartion(u8 copy_u8Line, u8 copy_u8PortMap);






#endif