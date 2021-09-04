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

beep_config bc = {.notes_per_measure = 4, .note_value = 4, .subdivisions = 1, .tempo = 60};

int main()
{
	metronome_init();
	sei();

	while (1)
	{
		beep_enc_value_control(&bc.tempo);
	}
}