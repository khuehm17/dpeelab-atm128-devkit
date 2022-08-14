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

#define STATE_MAXNUMBER				4u

#define APL_DEFAULT_SESSION			1u
#define APL_PRO_SESSION			    2u
#define APL_EXTEND_SESSION			3u

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
#define APL_EXECUTE_EVENT_COM				6u
#define APL_EXECUTE_EVENT_ENTRY				7u
#define APL_EXECUTE_EVENT_EXIT				8u

#define PMW_CLEAR 0u

typedef struct {
    uint8 ChanelA;
    uint8 chanelB;
    uint16 PMW;
	uint8 goStraight;
	uint8 goLeft;
	uint8 goRight;
	uint8 Session;
}ControllerStr;

typedef enum {
	CHANEL_CLEAR = 0,
	CHANEL_SET
}chanelControl;

ControllerStr *ControllerUnit;

uint8 Apl_gpioCurrentSts;
uint8 Apl_Counter;
uint8 Apl_FlagCom;

#endif /* PUBLIC_VARIABLE_H_ */