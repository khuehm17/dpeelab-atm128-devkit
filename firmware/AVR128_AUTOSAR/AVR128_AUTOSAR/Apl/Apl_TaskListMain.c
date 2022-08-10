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
	
	uint16 u2a_currentSts;
	
	u2a_currentSts = Apl_getCurrentSts();
	
	if (APL_TASKLIST_IDLE == u2a_currentSts) {
		if (ARG_TRUE == ControllerUnit->flag) {
			Apl_setEvt(APL_EXECUTE_EVENT_GOSTRAIGHT, NULL);
			ControllerUnit->flag = ARG_FALSE;
		} else {
			
		}	
	} else {
		
	}
	
	Apl_setEvt(APL_EXECUTE_EVENT_COM, NULL);
}


