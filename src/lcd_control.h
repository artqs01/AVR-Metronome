#ifndef LCD_CONTROL_H
#define LCD_CONTROL_H

#include <avr/io.h>

#define LCD_PORT PORTC

#define E_PIN 4
#define RS_PIN 5

#define RS_LOW LCD_PORT &= ~(1 << RS_PIN)
#define RS_HIGH LCD_PORT |= (1 << RS_PIN)
#define E_LOW LCD_PORT &= ~(1 << E_PIN)
#define E_HIGH LCD_PORT |= (1 << E_PIN)

void lcd_write_4bit(uint8_t rs, uint8_t data);
void lcd_write_byte(uint8_t rs, uint8_t data);
void lcd_mov_cur_x(int8_t shift_count);
void lcd_mov_cur_xy(uint8_t x, uint8_t y);
void lcd_printf(const char *format, ...);
void lcd_init();

#endif
