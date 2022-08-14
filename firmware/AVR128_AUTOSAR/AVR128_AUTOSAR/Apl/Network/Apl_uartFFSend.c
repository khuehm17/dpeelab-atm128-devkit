/*
 * Apl_uartFFSend.c
 *
 * Created: 7/30/2022 3:26:10 PM
 *  Author: ThoPH
 */ 

#include "Apl_uartFFSend.h"
#include <string.h>

void Apl_UART_RECEIVE(UART_Struct *buffer)
{
    UART1_RxString(buffer->Apl_BufferRead);
	return;
}

void Apl_UART_SEND(UART_Struct *buffer, uint16 size)
{
	return;
}