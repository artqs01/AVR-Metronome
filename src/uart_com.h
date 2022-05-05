
#define BAUD_RATE 9600

void uart_init();
void usart_putc(char c);
void uart_puts(const char* str);
void uart_printf(const char *format, ...);

