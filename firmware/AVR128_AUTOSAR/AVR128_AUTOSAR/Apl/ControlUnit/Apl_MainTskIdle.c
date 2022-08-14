/*
 * Apl_MainTskIdle.c
 *
 * Created: 7/30/2022 7:22:04 AM
 *  Author: ThoPH
 */

#include "Apl_MainTskIdle.h"

/**
  * @brief  Apl_mainIdle_EvReqGoStraight
  *         
  * @param
  * @param
  * @retval
  */
void Apl_mainIdle_EvReqGoStraight(void* para)
{
	Apl_gpioChangeState(APL_TASKLIST_GOSTRAIGHT, NULL);
	return;	
}

/**
  * @brief  Apl_mainIdle_EvReqGoLeft
  *         
  * @param
  * @param
  * @retval
  */
void Apl_mainIdle_EvReqGoLeft(void* para)
{
	Apl_gpioChangeState(APL_TASKLIST_GOLEFT, NULL);
	return;
}

/**
  * @brief  Apl_mainIdle_EvReqGoRight
  *         
  * @param
  * @param
  * @retval
  */
void Apl_mainIdle_EvReqGoRight(void* para)
{
	Apl_gpioChangeState(APL_TASKLIST_GORIGHT, NULL);
	return;
}

/**
  * @brief  Apl_mainIdle_EvJob
  *         
  * @param
  * @param
  * @retval
  */
void Apl_mainIdle_EvJob(void* para)
{

	return;
}

/**
  * @brief  Apl_mainIdle_entry
  *         
  * @param
  * @param
  * @retval
  */
void Apl_mainIdle_entry(void* para)
{
	return;
}

/**
  * @brief  Apl_mainIdle_exit
  *         
  * @param
  * @param
  * @retval
  */
void Apl_mainIdle_exit(void* para)
{
	return;
}


