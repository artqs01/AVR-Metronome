F_CPU = 20000000UL
MCU = atmega328p
CC = avr-gcc
CFLAGS = -O3 -mmcu=$(MCU) -DF_CPU=$(F_CPU) -flto -Wall -Wextra
SOURCES = beep.c encoder_control.c lcd_control.c uart_com.c metronome.c

LFUSE = 0xdf
HFUSE = 0xd1
EFUSE = 0xff

all: program.elf

program.elf: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $@

# -U flash:w:$^
# lfuse:w:$(LFUSE):m hfuse:w:$(HFUSE):m efuse:w:$(EFUSE):m

prog: program.elf
	avrdude -c usbasp -p $(MCU) -U flash:w:$^

prog_fuse: program.elf
	avrdude -c usbasp -p $(MCU) lfuse:w:$(LFUSE):m hfuse:w:$(HFUSE):m efuse:w:$(EFUSE):m

clean:
	-rm -f program.elf
