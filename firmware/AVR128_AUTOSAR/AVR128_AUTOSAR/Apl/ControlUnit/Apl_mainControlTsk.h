/*
 * Apl_mainControlTsk.h
 *
 * Created: 7/30/2022 7:07:52 AM
 *  Author: ThoPH
 */ 


#ifndef APL_MAINCONTROLTSK_H_
#define APL_MAINCONTROLTSK_H_

#include <Std_Type.h>
#include "Apl_Public_Variable.h"

typedef void (*MainControlSts) (void* para);

typedef struct {
	MainControlSts evtGoStraight;
	MainControlSts evtWaitGoStraight;
	MainControlSts evtGoLeft;
	MainControlSts evtWaitGoLeft;
	MainControlSts evtGoRight;
	MainControlSts evtWaitGoRigth;
	MainControlSts evtJob;
	MainControlSts evtEntry;
	MainControlSts evtExit;
} DC_Controller_sts;


void Apl_setEvt(uint8 evtJob, void* para);
uint16 Apl_getCurrentSts(void);
void Apl_gpioChangeState(uint16 currenstate, void* para);


#endif /* APL_MAINCONTROLTSK_H_ */