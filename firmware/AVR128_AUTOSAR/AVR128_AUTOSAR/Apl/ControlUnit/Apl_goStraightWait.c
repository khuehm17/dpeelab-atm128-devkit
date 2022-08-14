/*
 * Apl_goStraightWait.c
 *
 * Created: 8/6/2022 9:16:01 AM
 *  Author: phamh
 */ 
#include "Apl_goStraightWait.h"
#include "Apl_Public_Variable.h"

/**
  * @brief  Apl_mainGoStraightWait_EvEnd
  *         
  * @param
  * @param
  * @retval
  */
void Apl_mainGoStraightWait_EvEnd(void* para)
{
	if (E_OK == Apl_FlagCom) {
		Apl_gpioChangeState(APL_TASKLIST_IDLE, NULL);
	    clr_LCD();
		move_LCD(0,0);
		printf_LCD("Sts IDLE");
		move_LCD(2,0);
		printf_LCD("PROGRAMMING");
		
		Apl_FlagCom = E_NOTOK;
	}
	return;
}

/**
  * @brief  Apl_mainGoStraightWait_EvJob
  *         
  * @param
  * @param
  * @retval
  */
void Apl_mainGoStraightWait_EvJob(void* para)
{
	clr_LCD();
	move_LCD(0,0);
	printf_LCD("Sts GO STRAIGHT");
	move_LCD(2,0);
	printf_LCD("PROGRAMMING");

	PORTE ^= (1<<PE5);
    PORTE ^= (1<<PE4);
	_delay_ms(500);
	
	++Apl_Counter;
	
	if (20u == Apl_Counter) {
		Apl_FlagCom = E_OK;
		Apl_Counter = 0;
	}
	
    Apl_setEvt(APL_EXECUTE_EVENT_WAITGOSTRAIGHT, NULL);
	
	return;
}

/**
  * @brief  Apl_mainGoStraightWait_entry
  *         
  * @param
  * @param
  * @retval
  */
void Apl_mainGoStraightWait_entry(void* para)
{
	return;
}

/**
  * @brief  Apl_mainGoStraightWait_exit
  *         
  * @param
  * @param
  * @retval
  */
void Apl_mainGoStraightWait_exit(void* para)
{
	return;
}
