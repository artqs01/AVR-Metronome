#include <util/delay.h>

#include "encoder_control.h"

int8_t enc_move()
{
    static uint8_t last_a = 0;
    static int8_t move_counter = 0;

    if (last_a != ENC_SIGNAL_A)
    {
        move_counter += (ENC_SIGNAL_A == ENC_SIGNAL_B) ? 1 : -1;
    }

    last_a = ENC_SIGNAL_A;

    if (move_counter > 1)
    {
        move_counter = 0;
        return 1;
    }
    else if (move_counter < -1)
    {
        move_counter = 0;
        return -1;
    }
    else return 0;
}