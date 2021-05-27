/*
 * hardware.h
 *
 *  Created on: May 18, 2021
 *      Author: abema
 */

#ifndef INC_HARDWARE_H_
#define INC_HARDWARE_H_

#include <msp430.h>

#define SWITCH_1_PORT     4
#define SWITCH_1_PIN      BIT1
#define SWITCH_2_PORT     4
#define SWITCH_2_PIN      BIT0

#define LED_RED_PORT     4
#define LED_RED_PIN      BIT2
#define LED_GREEN_PORT   2
#define LED_GREEN_PIN    BIT7

#define RFM_IRQ_PORT    2
#define RFM_IRQ_PIN     BIT3
#define RFM_MISO_PORT   2
#define RFM_MISO_PIN    BIT5
#define RFM_MOSI_PORT   2
#define RFM_MOSI_PIN    BIT6
#define RFM_SCK_PORT    2
#define RFM_SCK_PIN     BIT4
#define RFM_CSN_PORT    3
#define RFM_CSN_PIN     BIT1
#define RFM_CE_PORT     3
#define RFM_CE_PIN      BIT4



#endif /* INC_HARDWARE_H_ */
