#ifndef ENCODER_CONTROL_H
#define ENCODER_CONTROL_H

#include <avr/io.h>

#define ENC_SWITCH (!!(PINB & (1 << 0)))
#define ENC_SIGNAL_A (!!(PINB & (1 << 1)))
#define ENC_SIGNAL_B (!!(PINB & (1 << 2)))

#define ENCODER_MOVE_SPEED_LIMIT F_CPU / 6

typedef struct encoder_state
{
    uint8_t last_clk;
	uint8_t move_flag;
	int8_t move_count;
	int8_t last_move;
	uint32_t speed_count;
} encoder_state;

int8_t enc_move();
void enc_speed_calc_begin();
void isr_enc_speed_check();

#endif