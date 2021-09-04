#include <util/delay.h>
#include <util/atomic.h>

#include "encoder_control.h"

int8_t enc_move()
{
    static int8_t last_clk = 0;
    static int8_t move_count = 0;

    if (last_clk != ENC_SIGNAL_A)
        move_count += (ENC_SIGNAL_A == ENC_SIGNAL_B) ? 1 : -1;

    last_clk = ENC_SIGNAL_A;

    if (move_count > 1)
        return 1;
    else if (move_count < -1)
        return -1;
    else
        return 0;
}