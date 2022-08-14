/*
 * Bsw.c
 *
 * Created: 7/17/2022 11:33:18 PM
 *  Author: ThoPH
 */ 

#include <Bsw.h>

LiquidCrystalDevice_t device;

static void IO_Init();
//static void LCD_Init(LiquidCrystalDevice_t* module);
static void f_uartInit(void);

static void IO_Init(){
	DDRE |= (1 << PE4) | (1 << PE5);
	PORTE &= ~((1 << PE4) | (1 << PE5));
}

// void LCD_Init(LiquidCrystalDevice_t* module) {
// 	*module = lq_init(0x27, 16, 2, LCD_5x8DOTS);
// 	lq_turnOnBacklight(module);
// }

static void f_uartInit(void) {
	UART1_Init(9600);
	return;
}

void BSW_driverInit(void)
{
	//WDT_Init(TIMEOUT_1S);
	f_uartInit();
	IO_Init();
	//LCD_Init(&device);
	init_LCD();

	return;
}