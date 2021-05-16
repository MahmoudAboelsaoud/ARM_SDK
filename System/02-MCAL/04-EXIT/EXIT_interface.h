/******************************************************/
/* Author      : Mahmoud Aboelsaoud                   */
/* Date        : 17 DCE 2020                          */
/* version     : V01                                  */
/* Descraption : EXIT APLS                   */
/******************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


/*MEXTI_boolInit set the sence mode  Raising/ Failing/ ONChange */
bool_t MEXTI_boolInit(void);
/*MEXTI_boolEnableEXTI enable the line */
bool_t MEXTI_boolEnableEXTI(u8 copy_u8Line);
/*MEXTI_boolDisableEXTI disable the line */
bool_t MEXTI_boolDisableEXTI(u8 copy_u8Line);
/*MEXTI_boolSwTrigger */
bool_t MEXTI_boolSwTrigger(u8 copy_u8Line);
/*MEXTI_boolSetSignalLatch to change the sence mode at the run time Raising/ Failing/ ONChange */
bool_t MEXTI_boolSetSignalLatch(u8 copy_u8Line, u8 copy_u8Mode);
/*MEXTI_boolSetCallBack callback function*/
bool_t MEXTI_boolSetCallBack(void (*ptr_cb)(void);







#endif
