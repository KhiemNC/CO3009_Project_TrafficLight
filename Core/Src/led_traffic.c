/*
 * led_traffic.c
 *
 *  Created on: Nov 12, 2024
 *      Author: nguye
 */

#include "led_traffic.h"

struct LedTrafficStruct ledWay0 =
{
	WAY0_LED_A_GPIO_Port,
	WAY0_LED_A_Pin,
	WAY0_LED_B_GPIO_Port,
	WAY0_LED_B_Pin
};

struct LedTrafficStruct ledWay1 =
{
	WAY1_LED_A_GPIO_Port,
	WAY1_LED_A_Pin,
	WAY1_LED_B_GPIO_Port,
	WAY1_LED_B_Pin
};

void turnRed(struct LedTrafficStruct* ledTraffic)
{
	HAL_GPIO_WritePin(ledTraffic->PORT_A, ledTraffic->PIN_A, SET);
	HAL_GPIO_WritePin(ledTraffic->PORT_B, ledTraffic->PIN_B, SET);
}

void turnYel(struct LedTrafficStruct* ledTraffic)
{
	HAL_GPIO_WritePin(ledTraffic->PORT_A, ledTraffic->PIN_A, SET);
	HAL_GPIO_WritePin(ledTraffic->PORT_B, ledTraffic->PIN_B, RESET);
}

void turnGrn(struct LedTrafficStruct* ledTraffic)
{
	HAL_GPIO_WritePin(ledTraffic->PORT_A, ledTraffic->PIN_A, RESET);
	HAL_GPIO_WritePin(ledTraffic->PORT_B, ledTraffic->PIN_B, SET);
}

void turnOff(struct LedTrafficStruct* ledTraffic)
{
	HAL_GPIO_WritePin(ledTraffic->PORT_A, ledTraffic->PIN_A, RESET);
	HAL_GPIO_WritePin(ledTraffic->PORT_B, ledTraffic->PIN_B, RESET);
}

void toggleRed()
{
	if (HAL_GPIO_ReadPin(ledWay0.PORT_A, ledWay0.PIN_A) == GPIO_PIN_SET)
	{
		turnOff(&ledWay0);
		turnOff(&ledWay1);
	}
	else
	{
		turnRed(&ledWay0);
		turnRed(&ledWay1);
	}
}

void toggleYel()
{
	if (HAL_GPIO_ReadPin(ledWay0.PORT_A, ledWay0.PIN_A) == GPIO_PIN_SET)
	{
		turnOff(&ledWay0);
		turnOff(&ledWay1);
	}
	else
	{
		turnYel(&ledWay0);
		turnYel(&ledWay1);
	}
}


void toggleGrn()
{
	if (HAL_GPIO_ReadPin(ledWay0.PORT_B, ledWay0.PIN_B) == GPIO_PIN_SET)
	{
		turnOff(&ledWay0);
		turnOff(&ledWay1);
	}
	else
	{
		turnGrn(&ledWay0);
		turnGrn(&ledWay1);
	}
}

