#include <util/delay.h>
#include <util/atomic.h>

#include "encoder_control.h"

static volatile encoder_state es = {.last_clk = 0, .move_flag = 0, .move_count = 0, .last_move = 0, .speed_count = F_CPU};

int8_t enc_move()
{
    if (es.last_clk != ENC_SIGNAL_A)
        es.move_count += (ENC_SIGNAL_A == ENC_SIGNAL_B) ? 1 : -1;

    es.last_clk = ENC_SIGNAL_A;

    if (es.move_count > 1)
        return 1;
    else if (es.move_count < -1)
        return -1;
    else
        return 0;
}

void enc_speed_calc_begin()
{
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
    {
        es.move_flag = 1;
        es.speed_count = 0;
    }
}

void isr_enc_speed_check()
{
    if(es.move_flag)
    {
        es.speed_count += (OCR2A + 1) << 10;
        if (es.speed_count > ENCODER_MOVE_SPEED_LIMIT)
            es.move_flag = 0;
    }
}