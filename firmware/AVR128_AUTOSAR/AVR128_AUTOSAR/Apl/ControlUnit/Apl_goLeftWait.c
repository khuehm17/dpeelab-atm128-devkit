/*
 * Apl_goLeftWait.c
 *
 * Created: 8/6/2022 9:16:45 AM
 *  Author: phamh
 */ 

#include "Apl_goLeftWait.h"
#include "Apl_Public_Variable.h"

/**
  * @brief  Apl_mainGoLeftWait_EvEnd
  *         
  * @param
  * @param
  * @retval
  */
void Apl_mainGoLeftWait_EvEnd(void* para)
{
	if (E_OK == Apl_FlagCom) {
		Apl_gpioChangeState(APL_TASKLIST_IDLE, NULL);
		clr_LCD();
		move_LCD(0,0);
		printf_LCD("Sts IDLE");
		move_LCD(2,0);
		printf_LCD("EXTEND");
		Apl_FlagCom = E_NOTOK;
	}
	return;
}

/**
  * @brief  Apl_mainGoLeftWait_EvJob
  *         
  * @param
  * @param
  * @retval
  */
void Apl_mainGoLeftWait_EvJob(void* para)
{
	clr_LCD();
	move_LCD(0,0);
	printf_LCD("Sts GO LEFT");
	move_LCD(2,0);
	printf_LCD("EXTEND");

	PORTE ^= (1<<PE4);
	_delay_ms(500);
	
	++Apl_Counter;
	
	if (20u == Apl_Counter) {
		Apl_FlagCom = E_OK;
		Apl_Counter = 0;
	}
	
	Apl_setEvt(APL_EXECUTE_EVENT_WAITGOLEFT, NULL);
	return;
}

/**
  * @brief  Apl_mainGoLeftWait_entry
  *         
  * @param
  * @param
  * @retval
  */
void Apl_mainGoLeftWait_entry(void* para)
{
	return;
}

/**
  * @brief  Apl_mainGoLeftWait_exit
  *         
  * @param
  * @param
  * @retval
  */
void Apl_mainGoLeftWait_exit(void* para)
{
	return;
}
