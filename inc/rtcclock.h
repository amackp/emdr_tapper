/*
 * rtcclock.h
 *
 *  Created on: Nov 19, 2017
 *      Author: spiri
 */

#ifndef RTCCLOCK_H_
#define RTCCLOCK_H_

#include <stdint.h>
#include <stdbool.h>

/* Day of week */
typedef enum {
    SUNDAY=0,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
} rtclock_dayofweek_t;

/* Month/Day/Year Hour:Minute:Second data */
typedef struct {
    rtclock_dayofweek_t dayofweek;
    uint8_t month;
    uint8_t day;
    uint16_t year;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
} rtclock_date_t;

/* Alarms */
typedef struct {
    // All declared volatile because the usermode can modify these on the fly, and the ISR reads them every time.
    volatile uint64_t timestamp;
    volatile bool triggered;
} rtclock_alarm_t;

#define RTC_MAX_ALARM_COUNT 2

/* Function prototypes */
void RTClock_init(uint64_t, uint32_t); // Configure RTC using SMCLK, must specify frequency
int RTClock_compare(uint64_t); // Compare specified date yielding -1 if it came before, 0 if same time, 1 if came after present time.
void RTClock_get(uint64_t *);  // Caller supplies a pointer to a 32-bit unsigned integer.
void RTClock_set(uint64_t new_value);
bool RTClock_setAlarm(rtclock_alarm_t *);
bool RTClock_clearAlarm(rtclock_alarm_t *);

/* The user may access the current clock timestamp directly instead of using RTClock_get().
 *
 * However, if you expect to perform multiple operations (comparisons, say) against it in a single
 * block of code, it might be useful to make a copy of this into a local variable first, as the counter
 * is liable to change at any time based on when the RTC interrupt fires.
 */
extern uint64_t rtcclock_current;

#endif /* RTCCLOCK_H_ */
