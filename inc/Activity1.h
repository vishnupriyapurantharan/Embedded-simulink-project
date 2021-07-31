/**
 * @file Activity1.h
 * @author Vishnu priya P (vishnupvspriya@gmail.com)
 * @brief contains all function prototypes
 * @version 0.1
 * @date 2021-07-27
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef ACTIVITY1_H_INCLUDED
#define ACTIVITY1_H_INCLUDED
/**
 * @brief function for configuring the registers
 * @param DDRx for denoting the direction of registers (i.e input or output)
 * @param PORTx for setting the bit at the respective register (i.e logic HIGH or logic LOW)
 */
void pin_config();

/**
 * @brief function for determining the status of LED actuator depending on the status of both passenger seat and heater button 
 * @return int 
 */
void Activity1();
#endif // ACTIVITY1_H_INCLUDED
