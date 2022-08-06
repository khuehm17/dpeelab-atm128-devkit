/*
 * Apl_MainTskIdle.c
 *
 * Created: 7/30/2022 7:22:04 AM
 *  Author: ThoPH
 */

#include "Apl_MainTskIdle.h"

void Apl_mainIdle_EvReqGoStraight(uint16 currentState, void* para)
{
	Apl_gpioChangeState(APL_TASKLIST_GOSTRAIGHT, NULL);
	return;	
}

void Apl_mainIdle_EvReqGoLeft(uint16 currentState, void* para)
{
	return;
}

void Apl_mainIdle_EvReqGoRight(uint16 currentState, void* para)
{
	return;
}

void Apl_mainIdle_EvJob(uint16 currentState, void* para)
{
	clr_LCD();
	move_LCD(0,0);
	printf_LCD("State IDLE");

	PORTE |= (1<<PE4);
	_delay_ms(1000);
	PORTE &= ~(1<<PE4);
	_delay_ms(1000);
	
	++Apl_Counter;
	
	if (3u == Apl_Counter) {
		ControllerUnit->flag = ARG_TRUE;
		Apl_Counter = 0;
	}
	
	return;
}


void Apl_mainIdle_entry(uint16 currentState, void* para)
{
	return;
}

void Apl_mainIdle_exit(uint16 currentState, void* para)
{
	return;
}

