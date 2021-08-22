#include <avr/interrupt.h>

#include "beep.h"

static volatile beep_status bs = {.ticks_for_beep = F_CPU, .tick_count = 0, .beep_flag = 0};

void metronome_init()
{
	DDRD |= (1 << PD6) | (1 << PD4);
	DDRB &= ~((1 << PINB0) | (1 << PINB1) | (1 << PINB2));

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
		bs.beep_flag = 1;
	}
}

void set_tempo(time_properties *tp)
{
	bs.ticks_for_beep = F_CPU * 4 * 60ull / (tp->tempo * tp->subdivisions * tp->note_value);
}

void beep_check(time_properties *tp)
{
	if (bs.beep_flag)
	{
		bs.beep_flag = 0;
		beep(tp);
	}
}

void beep(time_properties *tp)
{
	if (tp->subdivisions > 1 && tp->subdivision_count)
		OCR0A = 15;
	else
	{
		OCR0A = tp->beat_count ? 11 : 7;
		if (++tp->beat_count == tp->beats_per_measure)
			tp->beat_count = 0;
	}

	if (++tp->subdivision_count == tp->subdivisions)
			tp->subdivision_count = 0;

	TCNT1 = 0;
	TIMER1_START;
	
	TCCR0A |= (1 << COM0A0);
}
