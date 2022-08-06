/*
 * Public_Variable.h
 *
 * Created: 7/29/2022 11:22:06 PM
 *  Author: ThoPH
 */ 


#ifndef PUBLIC_VARIABLE_H_
#define PUBLIC_VARIABLE_H_

#include <Std_Type.h>
#include <user_config.h>
#include <Apl_mainControlTsk.h>

#define STATE_MAXNUMBER				3u

#define APL_TASKLIST_IDLE			0u
#define APL_TASKLIST_GOSTRAIGHT		1u
#define APL_TASKLIST_GOLEFT			2u
#define APL_TASKLIST_GORIGHT		3u

#define APL_EXECUTE_EVENT_GOSTRAIGHT		0u
#define APL_EXECUTE_EVENT_WAITGOSTRAIGHT	1u
#define APL_EXECUTE_EVENT_GOLEFT			2u
#define APL_EXECUTE_EVENT_WAITGOLEFT		3u
#define APL_EXECUTE_EVENT_GORIGHT			4u
#define APL_EXECUTE_EVENT_WAITGORIGHT		5u
#define APL_EXECUTE_EVENT_JOB				6u
#define APL_EXECUTE_EVENT_ENTRY				7u
#define APL_EXECUTE_EVENT_EXIT				8u

typedef struct {
    uint8 ChanelA;
    uint8 chanelB;
    uint16 PMW;
}ControllerStr;

const uint8 Apl_BufferRead[MAX_BLOCK_READ];
const uint8 Apl_BufferWrite[MAX_BLOCK_WRITE];
ControllerStr ControllerUnit;

uint8 Apl_gpioCurrentSts;

#endif /* PUBLIC_VARIABLE_H_ */