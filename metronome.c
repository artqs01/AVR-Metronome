#include <avr/io.h>
#include <avr/fuse.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "beep.h"
#include "encoder_control.h"

FUSES =
{
    0xdf, 0xd1, 0xff
};

ISR(TIMER2_COMPA_vect)
{
	isr_time_check();
	enc_speed_check();
}

ISR(TIMER1_COMPA_vect)
{
	TCCR0A &= ~(1 << COM0A0);
	TIMER1_STOP;
}

int main()
{
	time_properties tp = {.beat_count = 0, .beats_per_measure = 4, .note_value = 4, .subdivision_count = 0, .subdivisions = 7, .tempo = 60};
	int8_t d_bpm = 0;

	metronome_init();
	set_tempo(&tp);
	sei();
	
	while (1)
	{
		beep_check(&tp);
		d_bpm += enc_move();
		if (d_bpm)
		{
			tp.tempo += d_bpm;
			d_bpm = 0;
			enc_speed_calc_begin();
			set_tempo(&tp);
		}
	}
}