/*
 * DIO.c
 *
 *  Created on: Dec 24, 2021
 *      Author: DELL
 */

#include "STD_TYPES.h"
#include "MEMMAP.h"
#include "BIT_MATH.h"
#include "DIO_config.h"
#include "DIO.h"

/** @brief first function its about how to initalize the digital input output
 *  @param void
 *  @return void
 *
 * */
extern Uint8 DIO_PIN_CONFIGURATION[32];
void DIO_INIT(void)
{
	Uint8 pinstate;
	Uint8 pinvalue,portstate;
	Uint8 * reg[4]={DDRA_Adress,DDRB_Adress,DDRC_Adress,DDRD_Adress};
	Uint8 *  poerreg[4]={PORTA_Adress,PORTB_Adress,PORTC_Adress,PORTD_Adress};

	for (int i=0; i< PinLimit ;i++){
		pinvalue = i%8;
		portstate = i/8;
		pinstate=DIO_PIN_CONFIGURATION[i];
		switch (pinstate ){
		case OUTPUT :
			SET_BIT(*(reg[portstate]),pinvalue);
			break;
		case FREE :
			CLR_BIT(*(reg[portstate]),pinvalue);
			break;
		case INPUT :
			CLR_BIT(*(reg[portstate]),pinvalue);
			SET_BIT(*(poerreg[portstate]),pinvalue);
			break;
		}
	}
}
/** @brief first function its about how to Read the digital input output channel
 *  @param channel
 *  @return Uint8
 *
 * */

Uint8 DIO_READ_CHANNEL(Uint8 channel){

	Uint8 portstate,pinlevel,pinvalue;
	pinvalue  = channel%8;
	portstate = channel/8;
	Uint8*reg[4]={PINA_Adress,PINB_Adress,PINC_Adress,PIND_Adress};
	pinlevel = GET_BIT((*reg[portstate]),pinvalue);
	return pinlevel;

}
/** @brief first function its about how to write the digital input output channel
 *  @param channel level
 *  @return void
 *
 * */

void DIO_WRITE_CHANNEL(Uint8 channel,Uint8 level){

	Uint8 portstate,pinvalue;
		pinvalue  = channel%8;
		portstate = channel/8;
		Uint8*reg[4]={PORTA_Adress,PORTB_Adress,PORTC_Adress,PORTD_Adress};
		switch (level){
		case HIGH :
			SET_BIT((*reg[portstate]),pinvalue);
			break;
		case low :
			CLR_BIT((*reg[portstate]),pinvalue);

		}


}
/** @brief first function its about how to write the digital input output port
 *  @param port value
 *  @return void
 *
 * */
void DIO_WRITE_PORT(Uint8 PORT, Uint8 VALUE) {
	switch (PORT) {
	case PORT_A:
		PORTA_Register = VALUE;
		break;
	case PORT_B:
		PORTB_Register = VALUE;
		break;
	case PORT_C:
		PORTC_Register = VALUE;
		break;
	case PORT_D:
		PORTD_Register = VALUE;
		break;
	}
}

