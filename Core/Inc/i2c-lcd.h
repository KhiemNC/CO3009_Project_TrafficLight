#include "main.h"

#define SLAVE_ADDRESS_LCD 0x27 // 0x42
#define LCD_BUFFER_SIZE 16

extern char LCD_Buffer_Row0[LCD_BUFFER_SIZE];
extern char LCD_Buffer_Row1[LCD_BUFFER_SIZE];

void lcd_init (void);   // initialize lcd

void lcd_send_cmd (char cmd);  // send command to the lcd

void lcd_send_data (char data);  // send data to the lcd

void lcd_send_string (char *str);  // send string to the lcd

void lcd_put_cur(int row, int col);  // put cursor at the entered position row (0 or 1), col (0-15);

void lcd_clear (void);

void LCD_Display();
void update_LCD_buffer(uint8_t row, char *str);
