/**
 * @file Activity4.h
 * @author Vishnu priya P (vishnupvspriya@gmail.com)
 * @brief Header file for defining activity4
 * @version 0.1
 * @date 2021-07-27
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef ACTIVITY4_H_INCLUDED
#define ACTIVITY4_H_INCLUDED

void USARTInit(uint16_t ubrr_value);
/**
 * @brief for receiving data
 *
 */
char USARTReadChar();
/**
 * @brief For transmitting data
 *
 */
void USARTWriteChar(char data);
/**
 * @brief For defining activity4
 *
 */
void Activity4();

#endif // ACTIVITY4_H_INCLUDED
