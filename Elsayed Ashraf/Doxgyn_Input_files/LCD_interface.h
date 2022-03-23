#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/** @brief this is function Send the command to the LCD 
 * 
 * @param 8 bit command 
 *
 * @return void
 *
 */
void LCD_voidSendCommand(u8 Copy_u8Command);




/** @brief this is function Send the Data to the LCD 
 * 
 * @param 8 bit Data  
 *
 * @return void
 *
 */
void LCD_voidSendData(u8 Copy_u8Data);



/** @brief Initialization of  LCD 
 * 
 * Wait for more than 30ms after power up
 *
 * Then Use set command Function to initialize lines and font  
 * 1- 2 lines
 * 2- Font = 5*7
 *
 * Then Use set command Function to Display On Off control command
 *1- Display enable
 *2- Cursor off
 *3- Blink Cursor off
 *
 * @param void 
 *
 * @return void
 *
 */
void LCD_voidInit(void);



#endif