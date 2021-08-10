#include <avr/interrupt.h>
#include <avr/fuse.h>

#include "metronome.h"
#include "lcd_com.h"

volatile uint8_t meter = 4;
volatile uint8_t beat = 0;

FUSES = 
{
    0xdf, 0xd1, 0xff
};

ISR(TIMER1_COMPA_vect)										// rozpoczęcie generowania dźwięku
{
	OCR0A = beat ? 15 : 8;
	TCCR0A |= (1 << COM0A0);
	if (++beat == meter)
		beat = 0;
}

ISR(TIMER1_COMPB_vect)										// przerwanie generowania dźwięku
{
	TCCR0A &= ~(1 << COM0A0);
}

int main(void)
{
	DDRC = 0xff;
	DDRB = 0xff;
	DDRD = 0x0;
	DDRD |= (1 << 6);
	
	uint16_t bpm = 60;
	uint8_t subdivisions = 0;
	

	lcd_init();
	display_set_default();
	beep_init();
	lcd_move_cursor_on_address(0, 14);
	lcd_write_byte(1, 0xFF);
	sei();
	
	while (1)
	{
		if (RIGHT_BUTTON)
		{
			set_tempo(++bpm);
			lcd_move_cursor_on_address(0, 7);
			lcd_printf("   ");
			lcd_move_cursor_on_address(0, 7);
			lcd_printf("%d", bpm);
			while(RIGHT_BUTTON);
		}
		if (LEFT_BUTTON)
		{
			set_tempo(--bpm);
			lcd_move_cursor_on_address(0, 7);
			lcd_printf("   ");
			lcd_move_cursor_on_address(0, 7);
			lcd_printf("%d", bpm);
			while(LEFT_BUTTON);
		}
	}
}
