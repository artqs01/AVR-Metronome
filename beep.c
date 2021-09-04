#include "beep.h"
#include "encoder_control.h"

#include <avr/interrupt.h>
#include <util/atomic.h>

static volatile beep_state bs = {.ticks_for_beep = F_CPU, .tick_count = 0};

void metronome_init()
{
	DDRD |= (1 << PD6) | (1 << PD5);							// set output ports up
	DDRB &= ~((1 << PINB0) | (1 << PINB1) | (1 << PINB2));		// set input ports up

	TCCR0A = (1 << WGM01);
	TCCR0B = (1 << CS02) | (1 << CS00);							// set Timer 0 up (clear on compare match)
	OCR0A = 15;													// set Timer 0 register A value

	TCCR1A = 0;
	TCCR1C = 0;
	TCCR1B = (1 << WGM12);										// set Timer 1 up (clear on compare match)
	OCR1A = 700;												// set Timer 1 register A value
	TIMSK1 |= (1 << OCIE1A);									// interrupt enable for timer 1

	TCCR2A = (1 << WGM21);
	TCCR2B = (1 << CS22) | (1 << CS21) | (1 << CS20);			// set Timer 2 up (clear on compare match)
	TIMSK2 = (1 << OCIE2A);										// interrupt enable for timer 2

	OCR2A = 19;													// set Timer 2 register A value
}

void isr_time_check()
{
	bs.tick_count += (OCR2A << 10);
	if (bs.tick_count >= bs.ticks_for_beep)
	{
		bs.tick_count -= bs.ticks_for_beep;
		beep();
	}
}

void beep_config_update()
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		bs.ticks_for_beep = F_CPU * 60ull * 4 / (bc.note_value * bc.tempo * bc.subdivisions);
	}
}

void beep()
{
	if (bc.subdivisions > 1 && bc.cur_subdivision)
		OCR0A = 15;									// set Timer 0 register A value
	else
	{
		OCR0A = bc.beat ? 11 : 7;
		if (++bc.beat == bc.notes_per_measure)
			bc.beat = 0;
	}

	if (++bc.cur_subdivision == bc.subdivisions)
			bc.cur_subdivision = 0;

	TCNT1 = 0;										// clear Timer 1 counter
	TIMER1_START;
	
	TCCR0A |= (1 << COM0A0);						// enable "toggle output on compare match" for OCR1A output
}

void isr_beep_end()
{
	TCCR0A &= ~(1 << COM0A0);						// disable "toggle output on compare match" for OCR1A output
	TIMER1_STOP;
}