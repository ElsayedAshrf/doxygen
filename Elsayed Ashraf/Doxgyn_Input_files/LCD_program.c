#include "STD_TYPES.h"
#include <util/delay.h>

#include "DIO_interface.h"

#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"

/** @brief this is function
 * Set RW pin to write ,
 * Set Rs pin to command ,
 * Send the command to the LCD ,
 * Enable pulse
 *
 * @param 8 bit command 
 *
 * @return void
 *
 */
void LCD_voidSendCommand(u8 Copy_u8Command)
{
	/*Set RW pin to write*/
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RW_PIN,DIO_u8_PIN_LOW);

	/*Set Rs pin to command*/
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RS_PIN,DIO_u8_PIN_LOW);

	/*Send the command to the LCD*/
	DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Command);

	/*Enable pulse*/
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_PIN_HIGH);

	_delay_ms(2);

	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_PIN_LOW);
}





/** @brief this is function  
 * Set RW pin to write ,
 * Set Rs pin to Data ,
 * Send the Data to the LCD ,
 * Enable pulse
 * 
 * @param 8 bit Data  
 *
 * @return void
 *
 */
void LCD_voidSendData(u8 Copy_u8Data)
{
	/*Set RW pin to write*/
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RW_PIN,DIO_u8_PIN_LOW);

	/*Set Rs pin to Data*/
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RS_PIN,DIO_u8_PIN_HIGH);

	/*Send the Data to the LCD*/
	DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Data);

	/*Enable pulse*/
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_PIN_HIGH);

	_delay_ms(2);

	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_PIN_LOW);
}



/** @brief this is function  set basic Initialization of  LCD
 * 
 *
 * @param void 
 *
 * @return void
 *
 */
void LCD_voidInit(void)
{
	/*Wait for more than 30ms after power up*/
	_delay_ms(40);

	/*Function set command
	 * 1- 2 lines
	 * 2- Font = 5*7
	 * */
	LCD_voidSendCommand(0b00111000);

	/*Wait for more than 39us*/
	_delay_ms(1);

	/* Display On Off control command
	 * 1- Display enable
	 * 2- Cursor off
	 * 3- Blink Cursor off
	 * */
	LCD_voidSendCommand(0b00001100);

	/*Wait for more than 39us*/
	_delay_ms(1);

	/*LCD Clear*/
	LCD_voidSendCommand(0b00000001);

	/*Delay more than 1.53 ms*/
	_delay_ms(2);
}
