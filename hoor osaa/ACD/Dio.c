/*

 * Dio.c
 *
 *  Created on: Jan 8, 2022
 *      Author: pc
 */
#include "STD_Types.h"
#include "MEMMAP.h"
#include "BIT_MATH.h"
#include "DIO_CFG.h"
#include "DIO.h"
extern uint8 PINConfiguration[32];
void DIO_INIT(void)

{
	uint8* reg[8] = { DDRA_R, DDRB_R, DDRC_R, DDRD_R, PORTA_R, PORTB_R,
			PORTC_R, PORTD_R };
	uint8 pinstate;
	uint8 pinnom;
	uint8 portnom;
	for (uint8 i; i < PINLIMIT; i++) {
		pinnom = i % 8;
		portnom = i / 8;
		pinstate = PINConfiguration[i];
		switch (pinstate) {

		case INPUT:
			CLR_BIT(*reg[portnom], pinnom);
			CLR_BIT(*reg[portnom + 4], pinnom);

			break;

		case OUTPUT:
			SET_BIT(*reg[portnom], pinnom);
			break;

		case INPUT_PULLUP:

			CLR_BIT(*reg[portnom], pinnom);
			SET_BIT(*reg[portnom + 4], pinnom);

			break;
		}
	}
}

void DIO_WRITE_CHANNEL(uint8 channel, uint8 level) {
	uint8 pinnom;
	uint8 portnom;
	uint8 * reg[4] = { PORTA_R, PORTB_R, PORTC_R, PORTD_R };
	pinnom = channel % 8;
	portnom = channel / 8;
	switch (level) {
	case HIGH:
		SET_BIT(*reg[portnom], pinnom);
		break;

	case LOW:
		CLR_BIT(*reg[portnom], pinnom);

		break;
	}
}
uint8 DIO_READ_CHANNEL(uint8 channel) {
	uint8 x, pinnom;
	uint8 portnom;
	uint8 * reg[4] = { PINA_R, PINB_R, PINC_R, PIND_R };
	pinnom = channel % 8;
	portnom = channel / 8;
	x = GET_BIT(*reg[portnom], pinnom);
	return x;
}


void DIO_WRITE_PORT(uint8 PORT, uint8 VAL) {

	switch (PORT) {
	case PORT_A:
PORTA=VAL;
break;

	case PORT_B:
      PORTB=VAL;
		break;

	case PORT_C:
    PORTC=VAL;
     break;

   case PORT_D:
     PORTD=VAL;
			break;
	}
}#include "STD_Types.h"
#include "MEMMAP.h"
#include "BIT_MATH.h"
#include "DIO_CFG.h"
#include "DIO.h"
extern uint8 PINConfiguration[32];
void DIO_INIT(void)

{
	uint8* reg[8] = { DDRA_R, DDRB_R, DDRC_R, DDRD_R, PORTA_R, PORTB_R,
			PORTC_R, PORTD_R };
	uint8 pinstate;
	uint8 pinnom;
	uint8 portnom;
	for (uint8 i; i < PINLIMIT; i++) {
		pinnom = i % 8;
		portnom = i / 8;
		pinstate = PINConfiguration[i];
		switch (pinstate) {

		case INPUT:
			CLR_BIT(*reg[portnom], pinnom);
			CLR_BIT(*reg[portnom + 4], pinnom);

			break;

		case OUTPUT:
			SET_BIT(*reg[portnom], pinnom);
			break;

		case INPUT_PULLUP:

			CLR_BIT(*reg[portnom], pinnom);
			SET_BIT(*reg[portnom + 4], pinnom);

			break;
		}
	}
}

void DIO_WRITE_CHANNEL(uint8 channel, uint8 level) {
	uint8 pinnom;
	uint8 portnom;
	uint8 * reg[4] = { PORTA_R, PORTB_R, PORTC_R, PORTD_R };
	pinnom = channel % 8;
	portnom = channel / 8;
	switch (level) {
	case HIGH:
		SET_BIT(*reg[portnom], pinnom);
		break;

	case LOW:
		CLR_BIT(*reg[portnom], pinnom);

		break;
	}
}
uint8 DIO_READ_CHANNEL(uint8 channel) {
	uint8 x, pinnom;
	uint8 portnom;
	uint8 * reg[4] = { PINA_R, PINB_R, PINC_R, PIND_R };
	pinnom = channel % 8;
	portnom = channel / 8;
	x = GET_BIT(*reg[portnom], pinnom);
	return x;
}


void DIO_WRITE_PORT(uint8 PORT, uint8 VAL) {

	switch (PORT) {
	case PORT_A:
PORTA=VAL;
break;

	case PORT_B:
      PORTB=VAL;
		break;

	case PORT_C:
    PORTC=VAL;
     break;

   case PORT_D:
     PORTD=VAL;
			break;
	}
}

