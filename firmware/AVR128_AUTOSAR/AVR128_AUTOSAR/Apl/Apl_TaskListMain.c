/*
 * Apl_TaskListMain.c
 *
 * Created: 7/18/2022 12:52:11 AM
 *  Author: ThoPH
 */

#include <Apl_TaskListMain.h>
#include "Apl_Public_Variable.h"

/**
  * @brief  Apl_mainTask
  *         
  * @param
  * @param
  * @retval
  */
void Apl_mainTask(void) {
	
	Apl_gpioChangeState(Apl_gpioCurrentSts, NULL);
	
	if (ARG_TRUE == ControllerUnit->flag) {
		Apl_setEvt(APL_EXECUTE_EVENT_GOSTRAIGHT, NULL);
		ControllerUnit->flag = ARG_FALSE;
	}
	
	Apl_setEvt(APL_EXECUTE_EVENT_COM, NULL);
}


