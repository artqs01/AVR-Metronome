#include <avr/io.h>
#include <avr/fuse.h>
#include <util/delay.h>
#include <avr/interrupt.h>


ISR(TIMER1_COMPA_vect)
{
    PORTD |= (1 << 6);
    // TIFR1 |= (1 << OCF1A);
    // TIMSK1 &= ~(1 << OCIE1A);
    TCCR1B &= ~((1 << CS12) | (1 << CS10));
}

// MASK TIMSK
// FLAG TIFR

// (~TIFR) & MASK
// timer ustawia OCF1A na 0 zgłasza przerwanie
// obsługa przerwania ustawia OCF1A na 1


int main(void)
{
  TCCR1A = 0;
  TCCR1B = (1 << WGM12);
  TCCR1C = 0;
  TIMSK1 |= (1 << OCIE1A);
  OCR1A = 75*200;
  DDRD |= (1 << 6);

    // PORTB |= (1<<6);
    // _delay_ms(1000);
    // PORTB &= ~(1<<6);

 sei();

  while (1)
  {
	cli();
    PORTD &= ~(1 << 6);
    TCNT1 = 0;
    TCCR1B |= (1 << CS12) | (1 << CS10);
    // TIMSK1 |= (1 << OCIE1A);
    // TIFR1
	sei();
  _delay_ms(2000);
  }
}