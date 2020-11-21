/***********************************************/
/* Auther     : Mahmoud Aboelsaoud             */
/* Date       : 23 sep 2020                    */
/* Version    : V01                            */
/*Description : GPIO function                  */
/***********************************************/

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H


#define GPIO_HIGH     1
#define GPIO_LOW      0
/***********************************************************/
#define   GPIOA      0
#define   GPIOB      1
#define   GPIOC      2
/************************************************************/
#define   PIN0         0
#define   PIN1         1
#define   PIN2         2
#define   PIN3         3
#define   PIN4         4
#define   PIN5         5
#define   PIN6         6
#define   PIN7         7
#define   PIN8         8
#define   PIN9         9
#define   PIN10        10
#define   PIN11        11
#define   PIN12        12
#define   PIN13        13
#define   PIN14        14
#define   PIN15        15
/***************************************************************/

/*   Modes of input  */
#define   INPUT_FLOATING              0b0100
#define   INPUT_PULL_UP_DOWN          0b1000
#define   INPUT_ANALOG                0b0000

/*   Modes of output at 2MHZ      */
#define   OUTPUT_SPEED_2MHZ_PP        0b0010
#define   OUTPUT_SPEED_2MHZ_OD	      0b0110
#define   OUTPUT_SPEED_2MHZ_AFPP      0b1010
#define   OUTPUT_SPEED_2MHZ_AFOD      0b1110
/*   Modes of output at 10MHZ    */
#define   OUTPUT_SPEED_10MHZ_PP        0b0001
#define   OUTPUT_SPEED_10MHZ_OD	       0b0101
#define   OUTPUT_SPEED_10MHZ_AFPP      0b1001
#define   OUTPUT_SPEED_10MHZ_AFOD      0b1101
/*   Modes of output at 50MHZ    */
#define   OUTPUT_SPEED_50MHZ_PP        0b0011
#define   OUTPUT_SPEED_50MHZ_OD	       0b0111
#define   OUTPUT_SPEED_50MHZ_AFPP      0b1011
#define   OUTPUT_SPEED_50MHZ_AFOD      0b1111
/************************************************************/
/* GPIO_voidSetPinDirection function to set the direction of an pin 
   take the port and the pin number and the mode of work INPUT  ANALOG
													  INPUT  FLOATING
													  INPUT  PULL UP/DOWN
													  OUTPUT PUSH PULL
													  OUTPUT OPEN DRAIN
													  OUTPUT AF PUSH PULL
													  OUTPUT AF OPEN DRAIN
   and return viod*/
bool_t GPIO_voidSetPinDirection(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Mode);
/* GPIO_voidSetPinValue function to set an pin of an port ake the port and 
 the pin number and the value and return void*/
bool_t GPIO_u8SetPinValue(u8 copy_u8PORT, u8 copyPIN, u8 copy_u8value);
/* GPIO_u8GetPinValue function to get an pin value of an port take the port and 
 the pin number and return u8*/
u8 GPIO_u8GetPinValue(u8 copy_u8PORT, u8 copy_u8PIN);
/* GPIO_u8WriteValue function to write an value to the port the function take the GPIO port (copy_u8PORT) and 
   the value  (copy_u8value) and return bool_t status of the function */
bool_t GPIO_u8WriteValue(u8 copy_u8PORT, u8 copy_u8value);
/* GPIO_u8LockPinConfig function to lock the configuration mode on an GPIO pin the function take the port(copy_u8PORT)
  and the pin number (copy_u8PIN)and return bool_t status of the function */
bool_t GPIO_u8LockPinConfig(u8 copy_u8PORT, u8 copy_u8PIN);

#ifdef SPEED_UP_SET_RESET_OPERTION
/* GPIO_u8SpeedSetPinValue function to set pin direct in any port by using BERR in one operation the function take the
   port (copy_u8PORT)and the pin number(copyPIN) */
bool_t GPIO_u8SpeedSetPinValue(u8 copy_u8PORT, u8 copyPIN);
/* GPIO_u8SpeedClearPinValue function to clear pin direct in any port by using BRR in one operation the function take the
   port (copy_u8PORT)and the pin number(copyPIN) */
bool_t GPIO_u8SpeedClearPinValue(u8 copy_u8PORT, u8 copyPIN);

#endif






















#endif
