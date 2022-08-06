/*
 * Apl_goRightWait.h
 *
 * Created: 8/6/2022 9:17:10 AM
 *  Author: phamh
 */ 


#ifndef APL_GORIGHTWAIT_H_
#define APL_GORIGHTWAIT_H_

#include "Std_Type.h"

void Apl_mainGoRightWait_EvEnd(uint16 currentState, void* para);
void Apl_mainGoRightWait_EvJob(uint16 currentState, void* para);
void Apl_mainGoRightWait_entry(uint16 currentState, void* para);
void Apl_mainGoRightWait_exit(uint16 currentState, void* para);


#endif /* APL_GORIGHTWAIT_H_ */