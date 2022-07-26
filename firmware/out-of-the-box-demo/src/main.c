/*
* main.c
*
*  Created on: Mar 7, 2022
*      Author: khueh
*/

/*
*   Include header files
*/
#include <stdint.h>
#include <avr/io.h>
#include <avr/iom128.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include <util/delay.h>

/*
 *   Define macros
 */
/* Output Port pin LED */
#define PORT_LED_A        PORTE
#define DDR_LED_A         DDRE
#define BIT_LED_A         4

#define PORT_LED_B        PORTE
#define DDR_LED_B         DDRE
#define BIT_LED_B         5

#define PORT_SW_A         PORTE
#define DDR_SW_A          DDRE
#define BIT_SW_A          2

#define LED_BLINK_PERIOD  500

/**************************************************************************
 *                      User-defined Functions Prototype
 **************************************************************************/
void GPIO_Init(void);

/**************************************************************************
 *                           Global Declarations
 **************************************************************************/

/*
*   Main program
*/
int main(void)
{
    GPIO_Init();

    while(1)
    {
        PORT_LED_A |= (1 << BIT_LED_A);
        PORT_LED_B &= ~(1 << BIT_LED_B);
        _delay_ms(LED_BLINK_PERIOD);
        PORT_LED_A &= ~(1 << BIT_LED_A);
        PORT_LED_B |= (1 << BIT_LED_B);
        _delay_ms(LED_BLINK_PERIOD);
    };

    return 0;
}

/**************************************************************************
 *                 User-defined Functions Implementation
 **************************************************************************/
/* Initialize GPIOs */
void GPIO_Init(void)
{
    // Set LED as output pin
    DDR_LED_A |= (1 << BIT_LED_A);
    PORT_LED_A &= ~(1 << BIT_LED_A);

    // Set LED as output pin
    DDR_LED_B |= (1 << BIT_LED_B);
    PORT_LED_B &= ~(1 << BIT_LED_B);
}
