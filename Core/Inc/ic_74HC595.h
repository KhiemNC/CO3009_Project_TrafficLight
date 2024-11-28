/*
 * ic_74HC595.h
 *
 *  Created on: Sep 6, 2024
 *      Author: nguye
 */

#ifndef INC_IC_74HC595_H_
#define INC_IC_74HC595_H_

#include "main.h"
#include "common.h"

extern int enable7SEG;
extern int led_7seg_index;
extern int led_7seg_buffer[4];
extern int status_4digits[4];

void ic_74HC595_init();
void display_4digits();
void set_on_4digits();
void unable_4digits();
void update_led_7seg_buffer();
void transfer_8bit(uint8_t data);
void display_a_digit(uint8_t num, uint8_t digit);
uint8_t get_led7seg_number(uint8_t num);
uint8_t get_led7seg_digit(uint8_t num);

#endif /* INC_IC_74HC595_H_ */
