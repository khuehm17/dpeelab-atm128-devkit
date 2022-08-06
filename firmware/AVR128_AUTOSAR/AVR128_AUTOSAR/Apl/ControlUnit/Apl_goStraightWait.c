/*
 * Apl_goStraightWait.c
 *
 * Created: 8/6/2022 9:16:01 AM
 *  Author: phamh
 */ 
#include "Apl_goStraightWait.h"
#include "Apl_Public_Variable.h"

void Apl_mainGoStraightWait_EvEnd(uint16 currentState, void* para)
{
	if (E_OK == Apl_FlagCom) {
		Apl_gpioChangeState(APL_TASKLIST_IDLE, NULL);
		Apl_FlagCom = E_NOTOK;
	}
	return;
}

void Apl_mainGoStraightWait_EvJob(uint16 currentState, void* para)
{
	clr_LCD();
	move_LCD(0,0);
	printf_LCD("State GO STRAIGHT");

	PORTE |= (1<<PE5);
	_delay_ms(200);
	PORTE &= ~(1<<PE5);
	_delay_ms(200);
	
	++Apl_Counter;
	
	if (10u == Apl_Counter) {
		Apl_FlagCom = E_OK;
		Apl_Counter = 0;
	}
	
    Apl_setEvt(APL_EXECUTE_EVENT_WAITGOSTRAIGHT, NULL);
	
	return;
}

void Apl_mainGoStraightWait_entry(uint16 currentState, void* para)
{
	return;
}

void Apl_mainGoStraightWait_exit(uint16 currentState, void* para)
{
	return;
}