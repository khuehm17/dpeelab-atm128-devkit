/*
 * UDS_wModeUser_SID14.c
 *
 * Created: 8/6/2022 8:37:15 PM
 *  Author: phamh
 */ 

#include "UDS_wModeUser_SID14.h"
#include "avr/io.h"

void UDS_SID14changeRequest(uint8 *para) {
	switch (*para) {
		case 0x30: {
			if (APL_PRO_SESSION == ControllerUnit->Session) {
				ControllerUnit->goStraight = ARG_TRUE;
			}
			break;
		}
		case 0x31: {
			if (APL_PRO_SESSION == ControllerUnit->Session) {
				ControllerUnit->goRight = ARG_TRUE;
			}
			break;
		}
		case 0x32: {
			if (APL_EXTEND_SESSION == ControllerUnit->Session) {
				ControllerUnit->goLeft = ARG_TRUE;
			}
			break;
		}
		default: {
			break;
		}
	}
	
	return;
}