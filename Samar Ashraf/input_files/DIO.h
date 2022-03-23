/*
 * DIO.h
 *
 *  Created on: Dec 24, 2021
 *      Author: DELL
 */

#ifndef DIO_H_
#define DIO_H_

/** @brief first function its about how to initalize the digital input output
 *  @param void
 *  @return void
 *
 * */
void DIO_INIT(void);
/** @brief first function its about how to Read the digital input output channel
 *  @param channel
 *  @return Uint8
 *
 * */
void DIO_WRITE_CHANNEL(Uint8 channel,Uint8 level);
/** @brief first function its about how to write the digital input output channel
 *  @param channel level
 *  @return void
 *
 * */
Uint8 DIO_READ_CHANNEL(Uint8 channel);
/** @brief first function its about how to write the digital input output port
 *  @param port value
 *  @return void
 *
 * */
void DIO_WRITE_PORT (Uint8 (PORT),Uint8 VALUE);



#endif /* DIO_H_ */
