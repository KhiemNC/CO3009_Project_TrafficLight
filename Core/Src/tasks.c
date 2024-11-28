/*
 * tasks.c
 *
 *  Created on: Nov 11, 2024
 *      Author: nguye
 */


#include "tasks.h"

void t_get3ButtonInput()
{
	getKeyInput(&button0);
	getKeyInput(&button1);
	getKeyInput(&button2);
}

void t_blinkyLED()
{
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
}

void t_displayLed7Seg()
{
	if (enable7SEG == 1)
	{
		display_4digits();
	}
	else
	{
		unable_4digits();
	}
}