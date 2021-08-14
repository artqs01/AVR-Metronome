#include <avr/io.h>
#include <avr/fuse.h>
#include <util/delay.h>
#include <avr/interrupt.h>

FUSES = 
{
    0xdf, 0xd1, 0xff
};

volatile uint8_t beep_flag = 0;



volatile uint32_t ticks_for_beep = F_CPU - 1;
volatile uint32_t tick_count = 0;

void metronome_init()
{
	TCCR0A = (1 << WGM01);
	TCCR0B = (1 << CS02) | (1 << CS00);
	OCR0A = 15;

	TCCR1B = (1 << WGM12) | (1 << CS12) | (1 << CS10);
	TIMSK1 = (1 << OCIE1A);

	OCR1A = 750;

	TCCR2A = (1 << WGM21);
	TCCR2B = (1 << CS22) | (1 << CS21) | (1 << CS20);
	TIMSK2 = (1 << OCIE2A);

	OCR2A = 2;
}

void set_tempo(uint16_t bpm)
{
	ticks_for_beep = F_CPU * 60 / bpm - 1;
}

void beep();

ISR(TIMER2_COMPA_vect)
{
	tick_count += OCR2A << 10;
	if (tick_count >= ticks_for_beep)
	{
		tick_count -= ticks_for_beep;
		beep_flag = 1;
	}
}

int main()
{
	DDRB = 3;

	uint8_t time_signature = 4;
	uint8_t beat;

	uint8_t subdivisions = 1;
	uint8_t cur_subdivision;

	metronome_init();
	sei();

	while (1)
	{
		if (beep_flag)
		{
			beep();
			beep_flag = 0;
		}
	}
}
