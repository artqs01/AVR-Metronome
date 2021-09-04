#include <avr/interrupt.h>
#include <util/atomic.h>

#include "beep.h"

static volatile beep_status bs = {.ticks_for_beep = F_CPU, .tick_count = 0, .beep_flag = 0};

void metronome_init()
{
	DDRD |= (1 << PD6) | (1 << PD4);
	DDRB &= ~(1 << PD5);

	TCCR0A = (1 << WGM01);
	TCCR0B = (1 << CS02) | (1 << CS00);
	OCR0A = 15;

	TCCR1A = 0;
	TCCR1C = 0;
	TCCR1B = (1 << WGM12);
	OCR1A = 700;
	TIMSK1 |= (1 << OCIE1A);

	TCCR2A = (1 << WGM21);
	TCCR2B = (1 << CS22) | (1 << CS21) | (1 << CS20);
	TIMSK2 = (1 << OCIE2A);

	OCR2A = 19;
}

void isr_time_check()
{
    bs.tick_count += (OCR2A + 1) << 10;
	if (bs.tick_count >= bs.ticks_for_beep)
	{
		bs.tick_count -= bs.ticks_for_beep;
		beep();
	}
}

void set_tempo(uint16_t bpm, uint8_t subdivisions)
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
		bs.ticks_for_beep = F_CPU * 60 / (bpm * subdivisions);
}

void beep()
{
	if (subdivisions > 1 && *cur_subdivision)
		OCR0A = 15;
	else
	{
		OCR0A = *beat ? 11 : 7;
		if (++*beat == time_signature)
			*beat = 0;
	}

	if (++*cur_subdivision == subdivisions)
			*cur_subdivision = 0;

	TCNT1 = 0;
	TIMER1_START;
	
	TCCR0A |= (1 << COM0A0);
}
