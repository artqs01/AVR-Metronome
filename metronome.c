#include "beep.h"
#include "encoder_control.h"
#include "lcd_control.h"

#include <avr/io.h>
#include <avr/fuse.h>
#include <avr/interrupt.h>
#include <util/delay.h>

ISR(TIMER2_COMPA_vect)
{
	isr_time_check();
}

ISR(TIMER1_COMPA_vect)
{
	isr_beep_end();
}

volatile beep_config bc = {.notes_per_measure = 4, .note_value = 4, .subdivisions = 1, .tempo = 60, .beat = 0, .cur_subdivision = 0};

int main()
{
	metronome_init();
	sei();

	while (1)
	{
		if (enc_parameter_ctrl(&bc.tempo))
			beep_config_update();
	}
}
