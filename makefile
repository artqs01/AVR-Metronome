F_CPU = 20000000UL
MCU = atmega328p
CC = avr-gcc
CFLAGS = -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU) -flto -Wall -Wextra
SOURCES = alt_beep.c

all: program.elf

program.elf: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $@

prog: program.elf
	avrdude -c usbasp -p $(MCU) -Uflash:w:$^ -U lfuse:w:program.elf -U hfuse:w:program.elf -U efuse:w:program.elf
