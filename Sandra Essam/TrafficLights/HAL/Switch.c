

/**
 * @file Switch.c
 * @brief  it's used to read the value of switch and determine its type (pullup or pulldown)
 * @author Sandra Essam
 */
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include "DIO.h"
#include "Switch.h"


void
SW_INIT(uint8 PORT,uint8 PIN){
#if SW_TYPE == FREE_INPUT
	DIO_INIT_PIN_DIRECTION(PORT,PIN,INPUT);
#elif SW_TYPE == PULLUP_INPUT
	DIO_INIT_PIN_DIRECTION(PORT,PIN,INPUT);
	DIO_WRITE_PIN_VALUE(PORT, PIN, HIGH);
#endif

}
uint8
SW_READ(uint8 PORT,uint8 PIN){
uint8 value=0;
value=DIO_READ_PIN_VALUE(PORT,PIN);
return value;
}
