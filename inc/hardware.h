/*
 * hardware.h
 *
 *  Created on: May 18, 2021
 *      Author: abema
 */

#ifndef INC_HARDWARE_H_
#define INC_HARDWARE_H_

#include <msp430.h>

#define SWITCH_1_IN     P4IN
#define SWITCH_1        BIT1
#define SWITCH_2_IN     P4IN
#define SWITCH_2        BIT0

#define LED_RED_OUT     P4OUT
#define LED_RED         BIT2
#define LED_GREEN_OUT   P2OUT
#define LED_GREEN       BIT7


#endif /* INC_HARDWARE_H_ */
