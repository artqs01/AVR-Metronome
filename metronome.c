#include <avr/io.h>
#include <avr/fuse.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <util/atomic.h>

#include "beep.h"
#include "encoder_control.h"

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
	int8_t d_bpm = 0;

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
		d_bpm += enc_move();
		if (d_bpm)
		{
			bpm += d_bpm;
			ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
				set_tempo(bpm, subdivisions);
			d_bpm = 0;
		}
	}
}