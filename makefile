F_CPU = 20000000UL
MCU = atmega328p
CC = avr-gcc
CFLAGS = -O3 -mmcu=$(MCU) -DF_CPU=$(F_CPU) -flto -Wall -Wextra
SOURCES = beep.c encoder_control.c metronome.c

LFUSE = 0xdf
HFUSE = 0xd1
EFUSE = 0xff

all: program.elf

program.elf: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $@

prog: program.elf
	avrdude -c usbasp -p $(MCU) -Uflash:w:$^ -U lfuse:w:$(LFUSE):m -U hfuse:w:$(HFUSE):m -U efuse:w:$(EFUSE):m

clean:
	-rm -f program.elf
