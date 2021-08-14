#include "metronome.h"
#include "lcd_com.h"

#include <avr/interrupt.h>

void beep_init()
{
	TCCR1A = 0;
	TCCR1C = 0;												// wyłączenie niepotrzebnych rejestrów
	TCCR1B = (1 << WGM12) | (1 << CS12) | (1 << CS10);		// ustawienie w rejestrze TCCR1 trybu "clear timer on compare match" oraz ustawienie prescalera na 1024
	OCR1A = F_CPU * 60 / (60 * 1024ul) - 1;					// ustawienie tempa na 60 bpm
	OCR1B = 750;											// ustawienie dlugosci sygnalu bitu
	TIMSK1 = (1 << OCIE1A) | (1 << OCIE1B);					// włączenie przerwań dla włączenia sygnału metronomu i wyłączenia sygnału metronomu

	TCCR0A = (1 << WGM01);									// ustawienie w rejestrze TCCR0 trybu "clear timer on compare match"
	TCCR0B = (1 << CS02) | (1 << CS00);						// ustawienie prescalera Timera 0 na 1024
}

void display_set_default()
{
	lcd_printf("Tempo: 60");
	lcd_move_cursor_on_address(1, 0);
	lcd_printf("Meter: 4/4");
}

void set_tempo(uint16_t bpm)
{
	OCR1A = F_CPU * 60 / (bpm * 1024ul) - 1;
}

void tempo_change_mode()
{

}