/******************************************************/
/* Author      : Mahmoud Aboelsaoud                   */
/* Date        : 20 Nov 2020                          */
/* version     : V01                                  */
/* Descraption : NVIC private code                    */
/******************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H


/* the base address of NVIC */
#define NVIC_BASE_ADDRESS   0xE000E100

#define NVIC_ISER0  *((volatile u32*)(NVIC_BASE_ADDRESS + 0x000))/* Enable  the External interrupts from 0 to 31 */
#define NVIC_ISER1  *((volatile u32*)(NVIC_BASE_ADDRESS + 0x004))/* Enable  the External interrupts from 32 to 63*/
#define NVIC_ICER0  *((volatile u32*)(NVIC_BASE_ADDRESS + 0x080))/* Disable the External interrupts from 0 to 31 */
#define NVIC_ICER1  *((volatile u32*)(NVIC_BASE_ADDRESS + 0x084))/* Disable the External interrupts from 32 to 63*/
#define NVIC_ISPR0  *((volatile u32*)(NVIC_BASE_ADDRESS + 0x100))/* Interrupt Set Pending Register*/
#define NVIC_ISPR1  *((volatile u32*)(NVIC_BASE_ADDRESS + 0x104))
#define NVIC_ICPR0  *((volatile u32*)(NVIC_BASE_ADDRESS + 0x180))/* Interrupt Clear Pending Register*/
#define NVIC_ICPR1  *((volatile u32*)(NVIC_BASE_ADDRESS + 0x184))
#define NVIC_IABR0  *((volatile u32*)(NVIC_BASE_ADDRESS + 0x200))/*Interrupt Actove Bit Register*/
#define NVIC_IABR1  *((volatile u32*)(NVIC_BASE_ADDRESS + 0x204))





#endif