#include <avr/interrupt.h>
#include <util/atomic.h>

#include "beep.h"

static volatile beep_state bs = {.ticks_for_beep = F_CPU, .tick_count = 0};
static volatile time_properties tp = {.beat_count = 0, .beats_per_measure = 4, .note_value = 4, .subdivision_count = 0, .subdivisions = 1, .tempo = 60};

void metronome_init()
{
	DDRD |= (1 << PD6) | (1 << PD5);
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

void set_tempo(uint16_t bpm)
{
	tp.tempo = bpm;
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
		bs.ticks_for_beep = F_CPU * 4 * 60ull / (tp.tempo * tp.subdivisions * tp.note_value);
}

void isr_beep_check()
{
    bs.tick_count += (OCR2A + 1) << 10;
	if (bs.tick_count >= bs.ticks_for_beep)
	{
		bs.tick_count -= bs.ticks_for_beep;
		beep(tp);
	}
}

void beep()
{
	if (tp.subdivisions > 1 && tp.subdivision_count)
		OCR0A = 15;
	else
	{
		OCR0A = tp.beat_count ? 11 : 7;
		if (++tp.beat_count == tp.beats_per_measure)
			tp.beat_count = 0;
	}

	if (++tp.subdivision_count == tp.subdivisions)
			tp.subdivision_count = 0;

	TCNT1 = 0;
	TIMER1_START;
	
	TCCR0A |= (1 << COM0A0);
}

void isr_beep_end()
{
	TCCR0A &= ~(1 << COM0A0);
	TIMER1_STOP;
}