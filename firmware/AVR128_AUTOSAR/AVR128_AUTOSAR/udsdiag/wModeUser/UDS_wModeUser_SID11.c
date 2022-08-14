/*
 * UDS_wModeUser_SID11.c
 *
 * Created: 8/6/2022 8:37:30 PM
 *  Author: phamh
 */ 

#include "UDS_wModeUser_SID11.h"
#include "wdt.h"

void shutdown(uint8 *para) {
	wdt_enable(TIMEOUT_1S);
	while (1);
}