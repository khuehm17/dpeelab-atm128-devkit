/*
 * Apl_goLeftWait.h
 *
 * Created: 8/6/2022 9:16:53 AM
 *  Author: phamh
 */ 


#ifndef APL_GOLEFTWAIT_H_
#define APL_GOLEFTWAIT_H_

#include "Std_Type.h"

void Apl_mainGoLeftWait_EvEnd(uint16 currentState, void* para);
void Apl_mainGoLeftWait_EvJob(uint16 currentState, void* para);
void Apl_mainGoLeftWait_entry(uint16 currentState, void* para);
void Apl_mainGoLeftWait_exit(uint16 currentState, void* para);


#endif /* APL_GOLEFTWAIT_H_ */