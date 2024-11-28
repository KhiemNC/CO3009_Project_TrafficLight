/*
 * ic_74HC595.c
 *
 *  Created on: Sep 6, 2024
 *      Author: nguye
 */

#include "ic_74HC595.h"

#define DATA_SET HAL_GPIO_WritePin(DATA_GPIO_Port, DATA_Pin, GPIO_PIN_SET)
#define DATA_RESET HAL_GPIO_WritePin(DATA_GPIO_Port, DATA_Pin, GPIO_PIN_RESET)
#define CLK_SET HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin, GPIO_PIN_SET)
#define CLK_RESET HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin, GPIO_PIN_RESET)
#define LATCH_SET HAL_GPIO_WritePin(LATCH_GPIO_Port, LATCH_Pin, GPIO_PIN_SET)
#define LATCH_RESET HAL_GPIO_WritePin(LATCH_GPIO_Port, LATCH_Pin, GPIO_PIN_RESET)

#define LED7SEG_0 0xC0
#define LED7SEG_1 0xF9
#define LED7SEG_2 0xA4
#define LED7SEG_3 0xB0
#define LED7SEG_4 0x99
#define LED7SEG_5 0x92
#define LED7SEG_6 0x82
#define LED7SEG_7 0xF8
#define LED7SEG_8 0x80
#define LED7SEG_9 0x90

#define LED7SEG_DIGIT1 0x01
#define LED7SEG_DIGIT2 0x02
#define LED7SEG_DIGIT3 0x04
#define LED7SEG_DIGIT4 0x08

int enable7SEG = 1;
int led_7seg_index = 0;
int led_7seg_buffer[4] = {1, 2, 3, 4};
int status_4digits[4] = {LED_ON, LED_ON, LED_ON, LED_ON};

void ic_74HC595_init()
{
	HAL_GPIO_TogglePin(DATA_GPIO_Port, DATA_Pin);
	HAL_GPIO_TogglePin(CLK_GPIO_Port, CLK_Pin);
	HAL_GPIO_TogglePin(LATCH_GPIO_Port, LATCH_Pin);
	HAL_GPIO_WritePin(DATA_GPIO_Port, DATA_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LATCH_GPIO_Port, LATCH_Pin, GPIO_PIN_RESET);
}

void display_4digits()
{
	if ((status_4digits[led_7seg_index] == LED_ON)
			&& ((led_7seg_index == 1 && led_7seg_buffer[0])
					|| (led_7seg_index == 3 && led_7seg_buffer[2])
					|| led_7seg_buffer[led_7seg_index]))
	{
		display_a_digit(led_7seg_buffer[led_7seg_index], led_7seg_index);
	}
	++led_7seg_index;
	if (led_7seg_index > 3)
	{
		led_7seg_index = 0;
	}
}

void set_on_4digits()
{
	status_4digits[0] = LED_ON;
	status_4digits[1] = LED_ON;
	status_4digits[2] = LED_ON;
	status_4digits[3] = LED_ON;
}

void unable_4digits()
{
	transfer_8bit(0x00);
	transfer_8bit(0x00);
	LATCH_SET;
	LATCH_RESET;
}

void update_led_7seg_buffer()
{
	led_7seg_buffer[0] = (counter_way0 / 10) % 10;
	led_7seg_buffer[1] = counter_way0 % 10;
	led_7seg_buffer[2] = (counter_way1 / 10) % 10;
	led_7seg_buffer[3] = counter_way1 % 10;
}


void transfer_8bit(uint8_t data)
{
	uint8_t temp = 0;
	uint8_t i;

	for (i = 0; i < 8; ++i)
	{
		temp = data&0x80; // Only get bit MSD
		if (temp == 0x80) // 0b 1000 0000
		{
			DATA_RESET;
		}
		if (temp == 0x00)
		{
			DATA_SET;
		}
		CLK_SET;
		CLK_RESET;

		data = data << 1; // Shift left data 1 bit
	}
	DATA_RESET;
}


void display_a_digit(uint8_t num, uint8_t digit)
{
	transfer_8bit(get_led7seg_number(num));
	transfer_8bit(get_led7seg_digit(digit));
	LATCH_SET;
	LATCH_RESET;
}

uint8_t get_led7seg_number(uint8_t num)
{
	if (num == 0)
	{
		return LED7SEG_0;
	}
	if (num == 1)
	{
		return LED7SEG_1;
	}
	if (num == 2)
	{
		return LED7SEG_2;
	}
	if (num == 3)
	{
		return LED7SEG_3;
	}
	if (num == 4)
	{
		return LED7SEG_4;
	}
	if (num == 5)
	{
		return LED7SEG_5;
	}
	if (num == 6)
	{
		return LED7SEG_6;
	}
	if (num == 7)
	{
		return LED7SEG_7;
	}
	if (num == 8)
	{
		return LED7SEG_8;
	}
	if (num == 9)
	{
		return LED7SEG_9;
	}

	return 0x00;
}

uint8_t get_led7seg_digit(uint8_t num)
{
	if (num == 0)
	{
		return LED7SEG_DIGIT4;
	}
	if (num == 1)
	{
		return LED7SEG_DIGIT3;
	}
	if (num == 2)
	{
		return LED7SEG_DIGIT2;
	}
	if (num == 3)
	{
		return LED7SEG_DIGIT1;
	}

	return 0x00;
}
