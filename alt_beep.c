#include <avr/io.h>
#include <avr/fuse.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "metronome.h"

FUSES = 
{
    0xdf, 0xd1, 0xff
};

volatile uint8_t beep_flag = 0;

volatile uint32_t ticks_for_beep = F_CPU - 1;
volatile uint32_t tick_count = 0;

void metronome_init()
{
	DDRD |= (1 << PD6);

	TCCR0A = (1 << WGM01);
	TCCR0B = (1 << CS02) | (1 << CS00);
	OCR0A = 15;

	TCCR1B = (1 << WGM12) | (1 << CS12) | (1 << CS10);

	OCR1A = 750;

	TCCR2A = (1 << WGM21);
	TCCR2B = (1 << CS22) | (1 << CS21) | (1 << CS20);
	TIMSK2 = (1 << OCIE2A);

	OCR2A = 2;
}

void set_tempo(uint16_t bpm, uint8_t subdivisions)
{
	ticks_for_beep = F_CPU * 60 / (bpm * subdivisions) - 1;
}

void beep(uint8_t time_signature, uint8_t beat, uint8_t subdivisions, uint8_t cur_subdivision)
{
	// if(subdivisions > 1 && cur_subdivision)
	// 	OCR0A = 15;
	// else
	// {
	// 	OCR0A = beat ? 11 : 7;
	// 	if (++beat == time_signature)
	// 		beat = 0;
	// }

	// if (++cur_subdivision == subdivisions)
	// 		cur_subdivision = 0;

	// TCNT1 = 0;
	// TIMSK1 = (1 << OCIE1A);
	// TCCR0A = (1 << COM0A0);
	PORTD ^= (1 << PD6);
}

ISR(TIMER2_COMPA_vect)
{
	tick_count += OCR2A << 10;
	if (tick_count >= ticks_for_beep)
	{
		tick_count -= ticks_for_beep;
		beep_flag = 1;
	}
}

ISR(TIMER1_COMPA_vect)
{
	// TCCR0A &= ~(1 << COM0A0);
	// TIMSK1 &= ~(1 << OCIE1A);
	PORTD &= ~(1 << PD6);
}

int main()
{
	uint8_t time_signature = 4;
	uint8_t beat = 0;

	uint8_t subdivisions = 1;
	uint8_t cur_subdivision = 0;

	metronome_init();
	set_tempo(120, 1);
	sei();

	while (1)
	{
		if (beep_flag)
		{
			beep_flag = 0;
			beep(time_signature, beat, subdivisions, cur_subdivision);
		}
	}
}
