#pragma once

#include <avr/io.h>

#define BUZ_OUT 6
#define LEFT_BUTTON PIND & (1 << 2)
#define DOWN_BUTTON PIND & (1 << 3)
#define UP_BUTTON PIND & (1 << 4)
#define RIGHT_BUTTON PIND & (1 << 5)

void beep_init();
void display_set_default();
void set_tempo(uint16_t tempo);
void tempo_change_mode();
