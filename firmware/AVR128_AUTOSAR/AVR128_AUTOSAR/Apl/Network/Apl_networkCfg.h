/*
 * Apl_networkCfg.h
 *
 * Created: 8/13/2022 11:52:42 PM
 *  Author: phamh
 */ 


#ifndef APL_NETWORKCFG_H_
#define APL_NETWORKCFG_H_

#include "Std_Type.h"
#include "user_config.h"

typedef struct {
	uint8 Apl_BufferRead[MAX_BLOCK_READ];
	uint8 Apl_BufferWrite[MAX_BLOCK_WRITE];
}UART_Struct;

UART_Struct *UART_Data;

#endif /* APL_NETWORKCFG_H_ */