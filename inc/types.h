/*
 * types.h
 *
 *  Created on: May 18, 2021
 *      Author: abema
 */

#ifndef INC_TYPES_H_
#define INC_TYPES_H_

//Timings
#define SHUTDOWN_TIMEOUT_MS     (1000*60*10)    //10 min
#define RADIO_TIMEOUT_MS        (1000*60*1)     //1 min

#define STATUS_INDICATION_MS    50
#define HAPTIC_INFO_PULSE_MS    200


//State defintions
typedef enum{
    TAPPER_STATE_IDLE = 0,
    TAPPER_STATE_INPUT_DETERMINATION,
    TAPPER_STATE_SYNCED,
    TAPPER_STATE_SHUTDOWN_TIMEOUT,

    TAPPER_STATE_MAX
}tapper_state_t;

typedef enum{
    HAPTIC_STATE_STARTUP = 0,
    HAPTIC_STATE_NORMAL,
    HAPTIC_STATE_SHUTDOWN,
    HAPTIC_STATE_CHANGE_POLATITY,

    HAPTIC_STATE_MAX
}haptic_state_t;

typedef enum{
    LED_STATE_STARTUP = 0,
    LED_STATE_SYNCED,
    LED_STATE_NOT_SYNCED,

    LED_STATE_MAX
}led_state_t;


#endif /* INC_TYPES_H_ */
