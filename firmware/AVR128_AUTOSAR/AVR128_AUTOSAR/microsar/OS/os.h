/*
 * os.h
 *
 * Created: 8/6/2022 9:36:38 AM
 *  Author: phamh
 */ 


#ifndef OS_H_
#define OS_H_

#include "Std_Type.h"

#define WDG_ENTER_EXCLUSIVE(areaname)   SchM_Enter_Wdg_##areaname()
#define UART_ENTER_EXCLUSIVE(areaname)   SchM_Enter_UART_##areaname()
#define I2C_ENTER_EXCLUSIVE(areaname)   SchM_Enter_I2C_##areaname()
#define SPI_ENTER_EXCLUSIVE(areaname)   SchM_Enter_SPI_##areaname()
#define ADC_ENTER_EXCLUSIVE(areaname)   SchM_Enter_ADC_##areaname()

#endif /* OS_H_ */