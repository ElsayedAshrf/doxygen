
/**
 * @file main.c
 * @brief  it's used to make traffic light with seven segment counting descendingly from default (40) red light then yellow light in the list ten counts
 * then green light then yellow light ,etc,....
 * keypad controls the traffic counts
 * (*) modifies the counts of traffic light
 * (+) stops the traffic light
 * (-) resets the traffic light
 * @author Sandra Essam
 */
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include "DIO.h"
#include "Seven_Segment.h"
#include "Keypad.h"
#include <util/delay.h>

#define F_CPU 16000000

int main(void) {
	/*
	 * Intiallize 2-Seven Segment in same port & keypad & DIO direction
	 */
	SEVEN_SEG_INIT();
	KEYPAD_INIT();
	DIO_INIT_PORT_DIRECTION(PORT_C, OUTPUT);
        /*
         * num1 is number displayed in first 7 segment, num2 is number displayed in second 7 segment
         */
	uint8  Max_num = 40,num1 = Max_num/10, num2 = Max_num%10, count = 0,value, pin = PIN0, key,
			flag = 0;
	while (1) {
                
                /*
                 * display number in two 7 segments & the led
                 */ 
		DIO_WRITE_PIN_VALUE(PORT_C, pin, HIGH);
		DIO_WRITE_PIN_VALUE(PORT_C, PIN7, LOW);
		DIO_WRITE_PIN_VALUE(PORT_C, PIN6, HIGH);
		SEVEN_SEG_DISPLAY(num2);
		_delay_ms(100);
		DIO_WRITE_PIN_VALUE(PORT_C, PIN7, HIGH);
		DIO_WRITE_PIN_VALUE(PORT_C, PIN6, LOW);
		SEVEN_SEG_DISPLAY(num1);
		_delay_ms(100);
		key = KEYPAD_READ();
                /*
                 * options of the keypad
                 */    
		switch (key) {
		case '+':
                        /*
                         * flag decide to stop or continue numbers displaying & leds in 7 segments
                         */  
			flag ^= 1;
			break;
		case '-':
			num2 = Max_num%10;
			num1 = Max_num/10;
			count = 0;
			DIO_WRITE_PIN_VALUE(PORT_C, pin, LOW);
			pin=PIN0;
			break;
		case '*':
			Max_num = 0;
			DIO_WRITE_PIN_VALUE(PORT_C, PIN7, LOW);
			DIO_WRITE_PIN_VALUE(PORT_C, PIN6, LOW);
			do {
				key=KEYPAD_READ();
				value=HIGH;
				if(key>=0 && key<=9){
				Max_num = (Max_num * 10) + key;
				DIO_WRITE_PIN_VALUE(PORT_C, PIN7, value);
				DIO_WRITE_PIN_VALUE(PORT_C, PIN6, value^1);
				SEVEN_SEG_DISPLAY(Max_num%10);
				value^=value;}
			} while ((Max_num < 10 || Max_num > 99));
			num2 = Max_num%10;
			num1 = Max_num/10;
			count = 0;
			DIO_WRITE_PIN_VALUE(PORT_C, pin, LOW);
			pin=PIN0;
			break;
		default:
			if (flag == 0) {
				count++;
				if (count == Max_num) {
					num2 = Max_num%10;
					num1 = Max_num/10;
					count = 0;
					DIO_WRITE_PIN_VALUE(PORT_C, PIN2, LOW);
					DIO_WRITE_PIN_VALUE(PORT_C, pin, LOW);
					pin++;
					if (pin == PIN2) {
						pin= PIN0;
					}
				} else {
					if(count>=Max_num-10){
					 TOGGLE_BIT(PORTC, PIN2);
					 }
					if (num2 == 0) {
						num2 = 9;
						if (num1 == 0) {
							num1 = Max_num/10;;
						}
						else{
						num1--;}
					}
					else{
						num2--;
					}

				}

			}

		}


	}

	return 0;
}
