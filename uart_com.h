
#define BAUD_RATE 9600

void uart_init();
static inline void usart_putc(char c);
static inline void usart_puts(const char* str);
void usart_printf(const char *format, ...);

