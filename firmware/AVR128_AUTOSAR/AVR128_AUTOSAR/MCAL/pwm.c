/*
 * pwm.c
 *
 * Created: 8/7/2022 9:57:57 PM
 *  Author: phamh
 */ 

#include "avr/io.h"
#include <pwm.h>

void PWM_init()
{
	
	TCCR1A =  (1<<COM1A1)|(1<<COM1A0)|(1<<COM1B1)|(0<<COM1B0)
	|(0<<COM1C1)|(0<<COM1C0)|(1<<WGM11) |(1<<WGM10);

	TCCR1B =  (0<<ICNC1) |(0<<ICES1) |(0<<WGM13) |(0<<WGM12)
	|(0<<CS12)  |(1<<CS11)  |(0<<CS10);

	TCNT1 = 0;
	
	OCR1B =0;
	OCR1A = 0;

}






