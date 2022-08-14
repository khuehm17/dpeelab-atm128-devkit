/*
 * wdt.h
 *
 * Created: 8/13/2022 10:20:19 PM
 *  Author: phamh
 */ 


#ifndef WDT_H_
#define WDT_H_

#include "Std_Type.h"
#include "avr/io.h"
#include <avr/wdt.h>


typedef enum {
	TIMEOUT_15MS = 0,
	TIMEOUT_30MS,
	TIMEOUT_60MS,
	TIMEOUT_120MS,
	TIMEOUT_250MS,
	TIMEOUT_500MS,
	TIMEOUT_1S,
	TIMEOUT_2S	
}WDT_TIMING;

#define WDT_Init(timeout) wdt_enable(timeout)
#define WDT_Trigger() wdt_reset()
#define WDT_DISABLE() wdt_disable()
#define WDT_ENABLE(timeout) wdt_enable(timeout)

#endif /* WDT_H_ */