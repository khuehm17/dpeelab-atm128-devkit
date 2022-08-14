/*
 * UDS_ControllerTsk.h
 *
 * Created: 8/14/2022 2:07:41 AM
 *  Author: phamh
 */ 


#ifndef UDS_CONTROLLERTSK_H_
#define UDS_CONTROLLERTSK_H_

#include "UDS_wModeUser_SID10.h"
#include "UDS_wModeUser_SID11.h"
#include "UDS_wModeUser_SID31.h"
#include "UDS_wModeUser_SID14.h"

typedef struct {
	uint8 SID;
	void (*Func) (uint8*);	
}UDS_SERVICE;

static const UDS_SERVICE UDS_SERVICE_TABLE[3] = 
{
	{
		0x30, &UDS_SID10changeSession
	},
	{
		0x31, &shutdown
	},
	{
		0x32, &UDS_SID14changeRequest
	}
};

#endif /* UDS_CONTROLLERTSK_H_ */