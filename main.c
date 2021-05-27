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
    WDT_A_hold(WDT_A_BASE);

    gpio_init();
    clock_init();
    PMM_unlockLPM5();
    RTClock_init(0, INTERVAL_TIME);

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
    case TAPPER_STATE_SYNCED:
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

void gpio_init(){
    GPIO_setAsOutputPin(
            2,
            RFM_CSN_PIN + RFM_CE_PIN + LED_GREEN_PIN
            );

    GPIO_setAsOutputPin(
            3,
            RFM_MOSI_PIN + RFM_SCK_PIN
            );
    GPIO_setAsOutputPin(
            4,
            LED_RED_PIN
            );

    GPIO_setAsInputPin(
            RFM_MISO_PORT,
            RFM_MISO_PIN
            );

    GPIO_setAsInputPin(
            4,
            SWITCH_1_PIN + SWITCH_2_PIN
            );


    //XTAL
    P2OUT |= BIT4 + BIT6;
    GPIO_setAsPeripheralModuleFunctionInputPin(
        GPIO_PORT_P2,
        GPIO_PIN0 + GPIO_PIN1,
        GPIO_PRIMARY_MODULE_FUNCTION
    );

    //I2C
    GPIO_setAsPeripheralModuleFunctionInputPin(
        GPIO_PORT_P1,
        GPIO_PIN2 + GPIO_PIN3,
        GPIO_PRIMARY_MODULE_FUNCTION
    );


}

void reset_alarm(rtclock_alarm_t * alarm, uint16_t interval){
    RTClock_get(&alarm_time);
    alarm->timestamp = alarm_time + interval;
    RTClock_setAlarm(alarm);
}

void clock_init(){
    CS_initClockSignal(
        CS_FLLREF,
        CS_REFOCLK_SELECT,
        CS_CLOCK_DIVIDER_1
        );

    CS_initFLLSettle(8000, 244);

    CS_setExternalClockSource(32768);

    CS_initClockSignal(
        CS_SMCLK,
        CS_DCOCLKDIV_SELECT,
        CS_CLOCK_DIVIDER_8
        );
    CS_initClockSignal(
        CS_MCLK,
        CS_DCOCLKDIV_SELECT,
        CS_CLOCK_DIVIDER_1
        );

    CS_turnOnXT1LF(CS_XT1_DRIVE_0);


    volatile uint32_t m_freq = CS_getMCLK();
    volatile uint32_t sm_freq = CS_getSMCLK();
    volatile uint32_t a_feq = CS_getACLK();

    __delay_cycles(1);

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
