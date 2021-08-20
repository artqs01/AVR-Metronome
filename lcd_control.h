#ifndef LCD_CONTROL_H
#define LCD_CONTROL_H

#include <avr/io.h>

#define LCD_PORT PORTC

#define D4 0
#define D5 1
#define D6 2
#define D7 3
#define E 4
#define RS 5

#define RS_LOW PORTC &= ~(1 << RS)
#define RS_HIGH PORTC |= (1 << RS)
#define E_LOW PORTC &= ~(1 << E)
#define E_HIGH PORTC |= (1 << E)

void lcd_write_4bit(uint8_t rs, uint8_t data);
void lcd_write_byte(uint8_t rs, uint8_t data);
void lcd_move_cursor(int8_t shift_count);
void lcd_move_cursor_on_address(uint8_t x, uint8_t y);
void lcd_printf(const char *format, ...);
void lcd_init();

#endif