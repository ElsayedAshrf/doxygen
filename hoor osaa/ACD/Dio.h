/*
 * Dio.h
 *
 *  Created on: Jan 8, 2022
 *      Author: pc
 */
/** @file Dio.h
 *  @brief Function prototypes for the  Dio driver.
 *
 *  This contains the prototypes for the console
 *  driver and eventually any macros, constants,
 *  or global variables you will need.
 *
 *  @author Harry Q. Bovik (hqbovik)
 *  @author Fred Hacker (fhacker)
 *  @bug No known bugs.
 */


#ifndef DIO_H_
#define DIO_H_
/** @brief Prints character ch at the current location
 *         of the cursor.
 *
 *  If the character is a newline ('\n'), the cursor should
 *  be moved to the next line (scrolling if necessary).  If
 *  the character is a carriage return ('\r'), the cursor
 *  should be immediately reset to the beginning of the current
 *  line, causing any future output to overwrite any existing
 *  output on the line.  If backsapce ('\b') is encountered,
 *  the previous character should be erased (write a space
 *  over it and move the cursor back one column).  It is up
 *  to you how you want to handle a backspace occurring at the
 *  beginning of a line.
 *
 *  @param ch the character to print
 *  @return The input character
 */

void DIO_INIT (void);
/** @brief Prints the string s, starting at the current
 *         location of the cursor.
 *
 *  If the string is longer than the current line, the
 *  string should fill up the current line and then
 *  continue on the next line. If the string exceeds
 *  available space on the entire console, the screen
 *  should scroll up one line, and then the string should
 *  continue on the new line.  If '\n', '\r', and '\b' are
 *  encountered within the string, they should be handled
 *  as per putbyte. If len is not a positive integer or s
 *  is null, the function has no effect.
 *
 *  @param s The string to be printed.
 *  @param len The length of the string s.
 *  @return Void.
 */
void DIO_WRITE_CHANNEL(uint8 channel,uint8 level);
/** @brief Changes the foreground and background color
 *         of future characters printed on the console.
 *
 *  If the color code is invalid, the function has no effect.
 *
 *  @param color The new color code.
 *  @return Void.
 */
uint8 DIO_READ_CHANNEL(uint8 channel);
/** @brief used to read channel.
 *  @param color The address to which the current color
 *         information will be written.
 *  @return channel.
 */
void DIO_WRITE_PORT(uint8 PORT, uint8 VAL) ;
/** @brief Sets the position of the cursor to the
 *         position (row, col).
 *
 *  Subsequent calls to putbytes should cause the console
 *  output to begin at the new position. If the cursor is
 *  currently hidden, a call to set_cursor() must not show
 *  the cursor.
 *
 *  @param row The new row for the cursor.
 *  @param col The new column for the cursor.
 *  @return Void.
 */

#endif /* DIO_H_ */
