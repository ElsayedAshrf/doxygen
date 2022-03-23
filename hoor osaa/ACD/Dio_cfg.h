/*
 * Dio_cfg.h
 *
 *  Created on: Jan 8, 2022
 *      Author: pc
 */

#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#define HIGH 1
#define LOW 0
 typedef enum
 {
	 INPUT=0,
	 OUTPUT=1,
	 INPUT_PULLUP =2,


 } DIO_PINSTATE;

 typedef enum
  {
 	 PINA0 =0,
 	 PINA1 =1,
 	 PINA2 =2,
 	 PINA3 =3,
 	 PINA4 =4,
 	 PINA5 =5,
 	 PINA6 =6,
 	 PINA7 =7,
 	 PINB0 =8,
 	 PINB1 =9,
 	 PINB2 =10,
 	 PINB3 =11,
 	 PINB4 =12,
 	 PINB5 =13,
 	 PINB6 =14,
 	 PINB7 =15,
 	 PINC0 =16,
 	 PINC1 =17,
 	 PINC2 =18,
 	 PINC3 =19,
 	 PINC4=20,
 	 PINC5 =21,
 	 PINC6 =22,
 	 PINC7 =23,
 	 PIND0 =24,
 	 PIND1 =25,
 	 PIND2 =26,
 	 PIND3 =27,
 	 PIND4 =28,
 	 PIND5=29,
 	 PIND6 =30,
 	 PIND7 =31,
     PINLIMIT=32,



  } DIO_PINNAME;


  typedef enum
   {
  	 PORT_A=0,
  	 PORT_B=1,
  	 PORT_C=2,
     PORT_D=3,

   } DIO_PORTSTATE;


#endif /* DIO_CFG_H_ */
