 /*
 * TaskListMain.h
 *
 * Created: 7/18/2022 12:57:52 AM
 *  Author: ThoPH
 */ 


#ifndef APL_TASKLISTMAIN_H_
#define APL_TASKLISTMAIN_H_

#include <Bsw.h>
#include "Apl_mainControlTsk.h"
#include "Apl_uartFFSend.h"

void Apl_mainTask(void);
void Apl_controllerUnitTsk(void);

#endif /* TASKLISTMAIN_H_ */