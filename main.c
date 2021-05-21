//***************************************************************************************
//  EMDR Tapper Software
//  Created by Abe Maclean - abemaclean@gmail.com
//  April 2021 - Initial version v0.1
//***************************************************************************************

#include <msp430.h>
#include "driverlib.h"
#include "inc/types.h"
#include "inc/hardware.h"

tapper_state_t tapper_state;
haptic_state_t haptic_state;
led_state_t    led_state;

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

    //configure IO
    P1DIR =

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings


    for(;;) {
        tapper_sm();
        //LPM4;
    }
}

void tapper_sm(){

    switch(tapper_state){
    case TAPPER_STATE_INPUT_DETERMINATION:
        break;
    case TAPPER_STATE_IDLE:
        break;
    case TAPPER_STATE_SHUTDOWN_TIMEOUT:
        break;
    case TAPPER_STATE_SYNC:
        break;
    default:
        break;
    }

    switch(haptic_state){
    case HAPTIC_STATE_STARTUP:
        break;
    case HAPTIC_STATE_NORMAL:
        break;
    case HAPTIC_STATE_SHUTDOWN:
        break;
    case HAPTIC_STATE_CHANGE_POLATITY:
        break;
    default:
        break;
    }

    switch(led_state){
    case LED_STATE_STARTUP:
        break;
    case LED_STATE_SYNCED:
        break;
    case LED_STATE_NOT_SYNCED:
        break;
    default:
        break;
    }
}

#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=PORT4_VECTOR
__interrupt
#elif defined(__GNUC__)
__attribute__((interrupt(PORT4_VECTOR)))
#endif
void PORT4_ISR(void)
{

    GPIO_clearInterrupt(4, 0xff);
}
