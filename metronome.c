#include <avr/io.h>
#include <avr/fuse.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "beep.h"

FUSES = 
{
    0xdf, 0xd1, 0xff
};

ISR(TIMER2_COMPA_vect)
{
	isr_time_check();
}

ISR(TIMER1_COMPA_vect)
{
	TCCR0A &= ~(1 << COM0A0);
	TIMER1_STOP;
}

int main()
{
	uint16_t bpm = 60;

	uint8_t time_signature = 4;
	uint8_t beat = 0;

	uint8_t subdivisions = 1;
	uint8_t cur_subdivision = 0;

	metronome_init();
	set_tempo(bpm, subdivisions);
	sei();
	
	while (1)
	{
		beep_check(time_signature, &beat, subdivisions, &cur_subdivision);
	}
}