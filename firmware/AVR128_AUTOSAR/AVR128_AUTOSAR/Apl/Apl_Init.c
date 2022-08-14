/*
 * Apl_Init.c
 *
 * Created: 7/29/2022 11:51:01 PM
 *  Author: ThoPH
 */

#include <Apl_Init.h>
#include "string.h"
#include "Apl_Public_Variable.h"

/**
  * @brief  Apl_mainTaskStateInit
  *         
  * @param
  * @param
  * @retval
  */
void Apl_mainTaskStateInit(void)
{
	Apl_gpioCurrentSts = APL_TASKLIST_IDLE;
	Apl_setEvt(APL_EXECUTE_EVENT_ENTRY, NULL);
	
	clr_LCD();
	move_LCD(0,0);
	printf_LCD("Sts IDLE");
	return;
}

/**
  * @brief  Apl_networkInit
  *         
  * @param
  * @param
  * @retval
  */
void Apl_networkInit(void)
{
	memset((void*)UART_Data, ZERO, sizeof(UART_Struct));
	
	return;	
}

/**
  * @brief  Apl_controllerUnitInit
  *         
  * @param
  * @param
  * @retval
  */
void Apl_controllerUnitInit(void)
{
	memset((void*) ControllerUnit, 0, sizeof(ControllerStr));
	ControllerUnit->ChanelA = CHANEL_CLEAR;
	ControllerUnit->chanelB = CHANEL_CLEAR;
	ControllerUnit->PMW = PMW_CLEAR;
	ControllerUnit->goStraight = ARG_FALSE;
	ControllerUnit->goLeft = ARG_FALSE;
	ControllerUnit->goRight = ARG_FALSE;
	ControllerUnit->Session = APL_DEFAULT_SESSION;
	
	move_LCD(2,0);
	printf_LCD("DEFAULT");
	
	Apl_FlagCom = E_NOTOK;
	
	return;
}

/**
  * @brief  Apl_Init
  *         
  * @param
  * @param
  * @retval
  */
void Apl_Init(void)
{
	BSW_driverInit();
	//Apl_networkInit();
	Apl_mainTaskStateInit();
	Apl_controllerUnitInit();
	
	return;
}

