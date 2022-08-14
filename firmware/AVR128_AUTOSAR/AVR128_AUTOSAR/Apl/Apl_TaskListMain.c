/*
 * Apl_TaskListMain.c
 *
 * Created: 7/18/2022 12:52:11 AM
 *  Author: ThoPH
 */

#include <Apl_TaskListMain.h>
#include "Apl_Public_Variable.h"
#include "UDS_ControllerTsk.h"

/**
  * @brief  Apl_mainTask
  *         
  * @param
  * @param
  * @retval
  */
void Apl_mainTask(void) {
	uint16 u2a_currentSts;
	uint8 u1a_indx;
	
	u2a_currentSts = Apl_getCurrentSts();
	
	//WDT_DISABLE();
		
	if (APL_TASKLIST_IDLE == u2a_currentSts) {
		Apl_UART_RECEIVE(UART_Data);
	}
	
	//WDT_ENABLE(TIMEOUT_1S);
	
	for (u1a_indx = 0; sizeof(UDS_SERVICE_TABLE)/sizeof(UDS_SERVICE) > u1a_indx; u1a_indx++)
	{
		if (UART_Data->Apl_BufferRead[0] == UDS_SERVICE_TABLE[u1a_indx].SID) {
			 UDS_SERVICE_TABLE[u1a_indx].Func(&UART_Data->Apl_BufferRead[1]);
		}
	}
	
	Apl_controllerUnitTsk();
}

/**
  * @brief  Apl_controllerUnitTsk
  *         
  * @param
  * @param
  * @retval
  */
void Apl_controllerUnitTsk(void) {
	uint16 u2a_currentSts;
	
	u2a_currentSts = Apl_getCurrentSts();
	
	if (APL_TASKLIST_IDLE == u2a_currentSts) {
		
		switch(ControllerUnit->Session){
			case APL_PRO_SESSION:
			{
				clr_LCD();
				move_LCD(0,0);
				printf_LCD("Sts IDLE");
				move_LCD(2,0);
				printf_LCD("PROGRAMMING");
				
				if (ARG_TRUE == ControllerUnit->goStraight) {
					Apl_setEvt(APL_EXECUTE_EVENT_GOSTRAIGHT, NULL);
					ControllerUnit->goStraight = ARG_FALSE;
				}
				else if (ARG_TRUE == ControllerUnit->goRight) {
					Apl_setEvt(APL_EXECUTE_EVENT_GORIGHT, NULL);
					ControllerUnit->goRight = ARG_FALSE;
				} else {
					move_LCD(0,0);
					printf_LCD("Sts IDLE");
					Apl_setEvt(APL_EXECUTE_EVENT_COM, NULL);
				}
				break;
			}
			
			case APL_EXTEND_SESSION:
			{
				clr_LCD();
				move_LCD(0,0);
				printf_LCD("Sts IDLE");
				move_LCD(2,0);
				printf_LCD("EXTEND");
				if (ARG_TRUE == ControllerUnit->goLeft) {
					Apl_setEvt(APL_EXECUTE_EVENT_GOLEFT, NULL);
					ControllerUnit->goLeft = ARG_FALSE;
				} else {
					move_LCD(0,0);
					printf_LCD("Sts IDLE");
					Apl_setEvt(APL_EXECUTE_EVENT_COM, NULL);
				}
				break;
			}
			
			default:
				clr_LCD();
				move_LCD(0,0);
				printf_LCD("Sts IDLE");
				move_LCD(2,0);
				printf_LCD("DEFAULT");
				break;
		}
		
	} else {
		Apl_setEvt(APL_EXECUTE_EVENT_COM, NULL);
	}
}


