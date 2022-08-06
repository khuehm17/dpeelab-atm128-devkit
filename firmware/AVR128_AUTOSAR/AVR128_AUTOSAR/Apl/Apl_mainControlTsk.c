/*
 * Apl_mainControlTsk.c
 *
 * Created: 7/30/2022 7:08:01 AM
 *  Author: ThoPH
 */ 

#include <Apl_mainControlTsk.h>
#include "Apl_MainTskIdle.h"
#include <Apl_uartFFSend.h>

static const DC_Controller_sts Apl_stateMachine[2] = 
{
	{
		&Apl_mainIdle_EvReqWrite,
	    NULL,
		&Apl_mainIdle_EvReqErase,
		NULL,
		&Apl_mainIdle_EvReqVerify,
		NULL,
		&Apl_mainIdle_EvJob,
		&Apl_mainIdle_entry,
		&Apl_mainIdle_exit
	},
	{
		NULL,
		&Apl_mainWriteWait_EvEndWrite,
		NULL,
		NULL,
		NULL,
		NULL,
		&Apl_mainWriteWait_EvJob,
		&Apl_mainWriteWait_entry,
		&Apl_mainWriteWait_exit
	}
};


void Apl_gpioChangeState(uint16 currenstate, void* para)
{
	uint16 u2a_currentState;
	
	u2a_currentState = currenstate;
	
	if (STATE_MAXNUMBER <= currenstate) {
		Apl_stateMachine[currenstate].evtExit(u2a_currentState, NULL);
	}
	
	
	if (2 < u2a_currentState) {
		u2a_currentState = APL_TASKLIST_IDLE;
	}
	
	Apl_gpioCurrentSts = u2a_currentState;
	
	if (NULL != Apl_stateMachine[u2a_currentState].evtEntry) {
		Apl_stateMachine[u2a_currentState].evtEntry(currenstate, NULL);
	}
}

void Apl_setEvt(uint8 evtJob, void* para) {
	uint16 CurrentSts;
	
	MainControlSts Controller;

	CurrentSts = Apl_getCurrentSts();
	
	Controller = NULL;
	
	switch (evtJob)
	{
		case APL_EXECUTE_EVENT_GOSTRAIGHT:
		{
			Controller = Apl_stateMachine->evtGoStraight;
			break;
		}
		case APL_EXECUTE_EVENT_WAITGOSTRAIGHT:
		{
			Controller = Apl_stateMachine->evtWaitGoStraight;
			break;
		}
		case APL_EXECUTE_EVENT_GOLEFT:
		{
			Controller = Apl_stateMachine->evtGoLeft;
			break;
		}
		case APL_EXECUTE_EVENT_WAITGOLEFT:
		{
			Controller = Apl_stateMachine->evtWaitGoLeft;
			break;
		}
		case APL_EXECUTE_EVENT_GORIGHT:
		{
			Controller = Apl_stateMachine->evtGoRight;
			break;
		}
		case APL_EXECUTE_EVENT_WAITGORIGHT:
		{
			Controller = Apl_stateMachine->evtWaitGoRigth;
			break;
		}
		case APL_EXECUTE_EVENT_JOB:
		{
			Controller = Apl_stateMachine->evtJob;
			break;
		}
		case APL_EXECUTE_EVENT_ENTRY:
		{
			Controller = Apl_stateMachine->evtEntry;
			break;
		}
		case APL_EXECUTE_EVENT_EXIT:
		{
			Controller = Apl_stateMachine->evtExit;
			break;
		}
		default:
			break;
		
	}

	if (NULL != Controller) {
		Controller(CurrentSts, para);
	}
}

uint16 Apl_getCurrentSts(void)
{
	return Apl_gpioCurrentSts;
}