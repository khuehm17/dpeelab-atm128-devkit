/*
 * UDS_wModeUser_SID10.c
 *
 * Created: 8/6/2022 8:31:18 PM
 *  Author: phamh
 */ 

#include "UDS_wModeUser_SID10.h"
#include "Apl_Public_Variable.h"
#include "avr/io.h"

void UDS_SID10changeSession(uint8 *para) {
	switch (*para) {
		case 0x50: {
			ControllerUnit->Session = 0x01u;
			break;
		}
		case 0x51: {
			ControllerUnit->Session = 0x02u;
			break;
		}
		case 0x52: {
			ControllerUnit->Session = 0x03u;
			break;
		}
		default: {
			break;
		}
	}
	
	return;
}
