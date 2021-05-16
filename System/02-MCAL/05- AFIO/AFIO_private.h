/******************************************************/
/* Author      : Mahmoud Aboelsaoud                   */
/* Date        : 18 DCE 2020                          */
/* version     : V01                                  */
/* Descraption : AFIO code                            */
/******************************************************/


#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H


typedef struct
{
	u32 EVCR;
	u32 MAPR;
	u32 EXTICR[4];
	u32 MAPR2;
}AFIO_t;

#define  AFIO  ((volatile AFIO_t*)0x40010000)
/*the port map for each port */
#define 	PORTMAP_A    0b0000
#define 	PORTMAP_B    0b0001
#define 	PORTMAP_C    0b0010
#define 	PORTMAP_D    0b0011
#define 	PORTMAP_E    0b0100
#define 	PORTMAP_F    0b0101
#define 	PORTMAP_G    0b0110


#endif
