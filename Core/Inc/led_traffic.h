/*
 * led_traffic.h
 *
 *  Created on: Nov 12, 2024
 *      Author: nguye
 */

#ifndef INC_LED_TRAFFIC_H_
#define INC_LED_TRAFFIC_H_

#include "main.h"

struct LedTrafficStruct
{
	GPIO_TypeDef *PORT_A;
	uint16_t PIN_A;
	GPIO_TypeDef *PORT_B;
	uint16_t PIN_B;
};

extern struct LedTrafficStruct ledWay0;
extern struct LedTrafficStruct ledWay1;

void turnRed(struct LedTrafficStruct* ledTraffic);
void turnYel(struct LedTrafficStruct* ledTraffic);
void turnGrn(struct LedTrafficStruct* ledTraffic);
void turnOff(struct LedTrafficStruct* ledTraffic);
void toggleRed();
void toggleYel();
void toggleGrn();


#endif /* INC_LED_TRAFFIC_H_ */
