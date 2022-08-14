/*
 * Apl_uartFFSend.h
 *
 * Created: 7/30/2022 7:13:37 AM
 *  Author: ThoPH
 */ 


#ifndef APL_UARTFFSEND_H_
#define APL_UARTFFSEND_H_

#include "Apl_networkCfg.h"
#include "BSW_UART.h"

void Apl_UART_RECEIVE(UART_Struct *buffer);
void Apl_UART_SEND(UART_Struct *buffer, uint16 size);


#endif /* APL_UARTFFSEND_H_ */