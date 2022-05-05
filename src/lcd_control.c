#include "lcd_control.h"

#include <stdio.h>
#include <stdarg.h>
#include <util/delay.h>

void lcd_write_4bit(uint8_t rs, uint8_t data)
{
	if(rs)
		RS_HIGH;
	else
		RS_LOW;
	_delay_ms(1);
	E_HIGH;
	_delay_ms(1);
	LCD_PORT &= 0xf0;
	LCD_PORT |= (data & 0x0f);
	_delay_ms(1);
	E_LOW;
	_delay_ms(1);
}

void lcd_write_byte(uint8_t rs, uint8_t data)
{
	lcd_write_4bit(rs, (data >> 4));
	lcd_write_4bit(rs, data);
}

void lcd_init()
{
	_delay_ms(50);
	lcd_write_4bit(0, 0b0011);
	_delay_ms(10);
	lcd_write_4bit(0, 0b0011);
	_delay_ms(10);
	lcd_write_4bit(0, 0b0011);
	_delay_ms(12);
	lcd_write_4bit(0, 0b0010);

	lcd_write_4bit(0, 0b0010);
	lcd_write_4bit(0, 0b1000);

	lcd_write_4bit(0, 0b0000);
	lcd_write_4bit(0, 0b1000);

	lcd_write_4bit(0, 0b0000);
	lcd_write_4bit(0, 0b0001);

	lcd_write_byte(0, 0b110);

	lcd_write_byte(0, 0b1111);
}

void lcd_mov_cur_x(int8_t shift_count)
{
	while(shift_count > 0)
	{
		lcd_write_byte(0, 0b10100);
		--shift_count;
	}
	while(shift_count < 0)
	{
		lcd_write_byte(0, 0b10000);
		++shift_count;
	}
}

void lcd_mov_cur_xy(uint8_t x, uint8_t y)
{
	lcd_write_byte(0, (y ? 0xc0 : 0x80) | (x & 0x0f));
}

void lcd_printf(const char *format, ...)
{
	char buffer[16];

	va_list ap;
	va_start(ap, format);
	vsnprintf(buffer, sizeof buffer, format, ap);
	va_end(ap);

	for (char *c = buffer; *c; c++)
		lcd_write_byte(1, *c);
}
