#include <avr/io.h>
#include <avr/fuse.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "beep.h"
#include "encoder_control.h"
#include "lcd_control.h"

FUSES =
{
    0xdf, 0xd1, 0xff
};

ISR(TIMER2_COMPA_vect)
{
	isr_beep_check();
}

ISR(TIMER1_COMPA_vect)
{
	isr_beep_end();
}

int main()
{
	uint16_t bpm = 60;
	int8_t d_bpm = 0;

	metronome_init();
	set_tempo(60);

	sei();
	
	while (1)
	{
		d_bpm += enc_move();
		if (d_bpm)
		{
			bpm += d_bpm;
			d_bpm = 0;
			set_tempo(bpm);
		}
	}
}