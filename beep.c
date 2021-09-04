#include <avr/interrupt.h>
#include <util/atomic.h>

#include "beep.h"
#include "encoder_control.h"

static volatile beep_state bs = {.ticks_for_beep = F_CPU, .tick_count = 0};

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
		bs.ticks_for_beep = F_CPU * 60ull * 4 / (bc.note_value * bc.tempo * bc.subdivisions);
}

void beep()
{
	static uint8_t beat = 0;
	static uint8_t cur_subdivision = 0;

	if (bc.subdivisions > 1 && cur_subdivision)
		OCR0A = 15;
	else
	{
		OCR0A = beat ? 11 : 7;
		if (++beat == bc.notes_per_measure)
			beat = 0;
	}

	if (++cur_subdivision == bc.subdivisions)
			cur_subdivision = 0;

	TCNT1 = 0;
	TIMER1_START;
	
	TCCR0A |= (1 << COM0A0);
}

void isr_beep_end()
{
	TCCR0A &= ~(1 << COM0A0);
	TIMER1_STOP;
}

void beep_enc_value_control(uint16_t* parameter)
{
	static int8_t d_value = 0;

	d_value += enc_move();
		if (d_value)
		{
			*parameter += d_value;
			d_value = 0;
				beep_config_update();
		}
}