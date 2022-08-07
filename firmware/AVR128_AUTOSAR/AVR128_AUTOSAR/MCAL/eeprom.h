/*
 * eeprom.huint16
 *
 * Created: 8/6/2022 9:40:24 AM
 *  Author: phamh
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "Std_Type.h"

void EE_vWriteByte(uint16 u16Address, uint8 u8Data);
uint8 EE_u8ReadByte(uint16 u16Address);

#endif /* EEPROM_H_ */