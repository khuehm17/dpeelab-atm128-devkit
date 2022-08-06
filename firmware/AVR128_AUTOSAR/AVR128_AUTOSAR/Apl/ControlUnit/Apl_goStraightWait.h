/*
 * Apl_goStraightWait.h
 *
 * Created: 8/6/2022 9:15:52 AM
 *  Author: phamh
 */ 


#ifndef APL_GOSTRAIGHTWAIT_H_
#define APL_GOSTRAIGHTWAIT_H_

#include "Std_Type.h"
#include "Bsw.h"


void Apl_mainGoStraightWait_EvEnd(uint16 currentState, void* para);
void Apl_mainGoStraightWait_EvJob(uint16 currentState, void* para);
void Apl_mainGoStraightWait_entry(uint16 currentState, void* para);
void Apl_mainGoStraightWait_exit(uint16 currentState, void* para);


#endif /* APL_GOSTRAIGHTWAIT_H_ */