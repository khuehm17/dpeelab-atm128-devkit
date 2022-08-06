/*
 * Apl_MainTskIdle.h
 *
 * Created: 7/30/2022 7:21:47 AM
 *  Author: ThoPH
 */ 


#ifndef APL_MAINTSKIDLE_H_
#define APL_MAINTSKIDLE_H_

#include <Apl_mainControlTsk.h>
#include <Std_Type.h>
#include <Bsw.h>

void Apl_mainIdle_EvReqGoStraight(uint16 currentState, void* para);
void Apl_mainIdle_EvReqGoLeft(uint16 currentState, void* para);
void Apl_mainIdle_EvReqGoRight(uint16 currentState, void* para);
void Apl_mainIdle_EvJob(uint16 currentState, void* para);
void Apl_mainIdle_entry(uint16 currentState, void* para);
void Apl_mainIdle_exit(uint16 currentState, void* para);



#endif /* APL_MAINTSKIDLE_H_ */