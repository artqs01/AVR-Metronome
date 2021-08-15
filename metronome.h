#ifndef METRONOME_H
#define METRONOME_H

#include <avr/io.h>

#define BUZ_OUT 6
#define LEFT_BUTTON PIND & (1 << 2)
#define DOWN_BUTTON PIND & (1 << 3)
#define UP_BUTTON PIND & (1 << 4)
#define RIGHT_BUTTON PIND & (1 << 5)

void metronome_init();
void set_tempo(uint16_t bpm, uint8_t subdivisions);
void beep(uint8_t time_signature, uint8_t beat, uint8_t subdivisions, uint8_t cur_subdivision);

#endif