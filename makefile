F_CPU = 20000000UL
MCU = atmega328p
CC = avr-gcc
CFLAGS = -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU) -flto -Wall -Wextra
SOURCES = test.c metronome.c lcd_com.c

all: program.elf

program.elf: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $@

prog: program.elf
	avrdude -c usbasp -p $(MCU) -Uflash:w:$^ -Ulfuse:w:program.elf -Uhfuse:w:program.elf -Efuse:w:program.elf 
