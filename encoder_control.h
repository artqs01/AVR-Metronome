#ifndef ENCODER_CONTROL_H
#define ENCODER_CONTROL_H

#include <avr/io.h>

#define ENC_SWITCH (!!(PINB & (1 << 0)))
#define ENC_SIGNAL_A (!!(PINB & (1 << 1)))
#define ENC_SIGNAL_B (!!(PINB & (1 << 2)))

int8_t enc_move();
uint8_t enc_parameter_ctrl(volatile uint16_t* parameter);

#endif