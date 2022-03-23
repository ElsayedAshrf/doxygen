/** @file LCD.h
 *
 *	used macros and functions to display LCD 
 *
 *  Created on: 14/01/2022
 *      @author SalmaAbdeen
 */



#ifndef LCD_H_
#define LCD_H_

/* -- MACROS -- */

#define CLEAR_DISPLAY 0x01
#define RETURN_HOME 0x02
#define ENTRY_MODE_SET 0x06
#define DISPLAY_ON_CONTROL 0x0f
#define DISPLAY_OFF_CONTROL 0x08
#define DISPLAY_ON_CURSOR 0x0e
#define DISPLAY_SHIFT_CURSOR_LEFT 0x10
#define DISPLAY_SHIFT_CURSOR_RIGHT 0x14
#define SHIFT_DISPLAY_LEFT 0x18
#define SHIFT_DISPLAY_RIGHT 0x1c
#define SET_FUNCTION 0x38
#define SET_CGRAM_ADDRESS 0x40 //64
#define SET_DDRAM_ADDRESS 0x80 //128

/** @brief LCD initialition 
 * 
 * function to initial the LCD to be active
 * by specific steps as in data sheet
 * 
 * @param No parameter need
 * @return Should not return
 */

extern void LCD_Init (void);

/** @brief Send command 
 * 
 * function to send command to the lcd to do
 * by specific steps as in data sheet
 * 
 * @param command the command to exectute
 * @return Should not return
 */

extern void LCD_VidSendCommand (uint8 Command);

/** @brief print one character
 * 
 * function to send character to the lcd to show it
 * by specific steps as in data sheet
 * 
 * @param data the character to print
 * @return Should not return
 */

extern void LCD_VidSendChar (uint8 Data);

/** @brief move cursor
 * 
 * function to go to specific row and column in lcd
 * 
 * @param x the number of row wanted to go
 * @param y the number of column wanted to go
 * @return Should not return
 */

extern void LCD_VidGoToxy (uint8 x,uint8 y);

/** @brief print string of character
 * 
 * function to send string to show it to lcd
 * by using LCD_vidSendChar function and string as  array of char
 * 
 * @param string the array wanted to prin
 * @param index the length of characters must be print from array
 * @return Should not return
 */

extern void LCD_VidSendString (uint8 *StringCpy,uint8 Index);

/** @brief print one character
 * 
 * function to save and show extra string to show it to lcd
 * by using LCD_vidSendChar function and Extra_char array
 * 
 * @param x the number of row wanted to print in
 * @param y the number of column wanted to print in
 * @return Should not return
 */

extern void LCD_vidWriteExtraChar (uint8 X,uint8 Y);

#endif /* LCDH_ */
