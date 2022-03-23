/*
 * Dio_cfg.c
 *
 *  Created on: Jan 8, 2022
 *      Author: pc
 */


#include "STD_Types.h"
#include "DIO_CFG.h"

uint8 PINConfiguration[32]=


{
		INPUT_PULLUP, //portA PIN0
		INPUT_PULLUP, //portA PIN1
		INPUT_PULLUP, //portA PIN2
		INPUT_PULLUP, //portA PIN3
		OUTPUT,  //portA PIN4
		OUTPUT,  //portA PIN5
		OUTPUT,  //portA PIN6
     	OUTPUT,   //portA PIN7

		OUTPUT,  //portB PIN0
		OUTPUT,  //portB PIN1
		OUTPUT,  //PORTB PIN2
		OUTPUT,  //PORTB PIN3
		OUTPUT, //PORTB PIN4
		OUTPUT,   //PORTB PIN5
		OUTPUT, //PORTB PIN6
        OUTPUT, //PORTB PIN7

        OUTPUT,//PORTC PIN0
        OUTPUT,//PORT PIN1
        OUTPUT,//PORT PIN2
         INPUT,//PORT PIN3
         INPUT,//PORT PIN4
         INPUT,//PORT PIN5
         INPUT,//PORT PIN6
         INPUT,//PORT PIN7

         OUTPUT,//PORT PIN0
         OUTPUT,//PORT PIN1
         OUTPUT,//PORT PIN2
         OUTPUT,//PORT PIN3
         OUTPUT,//PORT PIN4
         OUTPUT,//PORT PIN5
         OUTPUT,//PORT PIN6
         OUTPUT,//PORT PIN7





};
