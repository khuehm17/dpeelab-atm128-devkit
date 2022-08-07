/*
 * eeprom.c
 *
 * Created: 8/6/2022 9:40:11 AM
 *  Author: phamh
 */ 

#include "eeprom.h"
#include <avr/interrupt.h>

void EE_vWriteByte(uint16 u16Address, uint8 u8Data)
{
	uint8 u8Sreg;
	
	while(EECR&(1<<EEWE));
	
	EEARL = u16Address & 0xff;
	EEARH = (u16Address >> 8) & 0xff;
	EEDR = u8Data;
	
	u8Sreg = SREG;
	
	cli();
	
	EECR |= (1 << EEMWE);
	EECR |= (1 << EEWE);
	SREG = u8Sreg;
}

uint8 EE_u8ReadByte(uint16 u16Address)
{
	while(EECR&(1<<EEWE));
	
	EEARL = u16Address&0xff;
	EEARH = (u16Address>>8)&0xff;
	
	EECR |= (1<<EERE);
	
	return EEDR;
}