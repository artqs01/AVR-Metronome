#include "beep.h"
#include "encoder_control.h"
#include "lcd_control.h"
#include "uart_com.h"

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

int main()
{
	metronome_init();
	uart_init();
	sei();
	volatile beep_config bc =
	{
		.notes_per_measure = 4,
		.note_value = 4,
		.subdivisions = 1,
		.tempo = 120,
		.beat = 0,
		.cur_subdivision = 0
	};
	while (1)
	{
		if (enc_parameter_ctrl(&bc.tempo) > 0)
		{
			beep_config_update();
		}
	}
}
