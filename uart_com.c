#include "uart_com.h"

void uart_init()
{
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);
    UCSR0C = (1 << UCSZ00) | (1 << UCSZ01);
    UBRR0 = (uint16_t) (F_CPU / 16 / BAUD_RATE - 1);
}

static inline void usart_putc(char c)
{
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = c;
}

static inline void usart_puts(const char* str)
{
    while(*str)
        usart_putc(*str++);
}

void usart_printf(const char *format, ...)
{
    char buffer[16];

    va_list ap;
    va_start(ap, format);
    vsnprintf(buffer, sizeof(buffer), format, ap);
    va_end(ap);

    usart_puts(buffer);
}

