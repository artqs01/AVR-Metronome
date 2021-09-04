#ifndef BEEP_H
#define BEEP_H

#include <avr/io.h>

#define BUZ_OUT 6
#define LEFT_BUTTON (!!(PIND & (1 << 2)))
#define DOWN_BUTTON (!!(PIND & (1 << 3)))
#define UP_BUTTON (!!(PIND & (1 << 4)))
#define RIGHT_BUTTON (!!(PIND & (1 << 5)))

#define TIMER1_START (TCCR1B |= (1 << CS12) | (1 << CS10))
#define TIMER1_STOP  (TCCR1B &= ~((1 << CS12) | (1 << CS10)))

typedef struct beep_state
{
    uint32_t ticks_for_beep;
    uint32_t tick_count;
    uint8_t beep_flag;
} beep_state;

typedef struct time_properties 
{
    uint8_t beats_per_measure;
    uint8_t beat_count;
    uint8_t note_value;
    uint8_t subdivisions;
    uint8_t subdivision_count;
    uint16_t tempo;
} time_properties;

typedef struct beep_config 
{
    uint8_t notes_per_measure;
    uint8_t note_value;
    uint8_t subdivisions;
    uint16_t tempo;
} beep_config;

extern beep_config bc;

void metronome_init();
void isr_time_check();
void beep_config_update();
void beep_check(uint8_t time_signature, uint8_t *beat, uint8_t subdivisions, uint8_t *cur_subdivision);
void beep();
void beep_enc_value_control(uint16_t* parameter);

#endif