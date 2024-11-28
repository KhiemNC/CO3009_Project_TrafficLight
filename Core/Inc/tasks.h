/*
 * tasks.h
 *
 *  Created on: Nov 11, 2024
 *      Author: nguye
 */

#ifndef INC_TASKS_H_
#define INC_TASKS_H_

#include "main.h"
#include "button.h"
#include "led_traffic.h"
#include "ic_74HC595.h"

void t_get3ButtonInput();
void t_blinkyLED();
void t_turnAllRed();
void t_turnAllYel();
void t_turnAllGrn();
void t_turnAllOff();

void t_checkKey();
void t_displayLed7Seg();

#endif /* INC_TASKS_H_ */
