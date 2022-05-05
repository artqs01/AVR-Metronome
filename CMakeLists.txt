project(avr_metronome)
cmake_minimum_required(VERSION 3.3)

set(CMAKE_C_COMPILER "/usr/bin/avr-gcc")
set(CMAKE_C_STANDARD 17)
set(F_CPU "20000000UL")
set(MCU "atmega328p")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -O3 -mmcu=${MCU} -DF_CPU=${F_CPU} -flto")

add_executable(avr_metronome
	"${PROJECT_SOURCE_DIR}/src/encoder_control.c"
	"${PROJECT_SOURCE_DIR}/src/lcd_control.c"
	"${PROJECT_SOURCE_DIR}/src/beep.c"
	"${PROJECT_SOURCE_DIR}/src/metronome.c"
	"${PROJECT_SOURCE_DIR}/src/uart_com.c"
)

target_link_libraries(avr_metronome)
target_include_directories(avr_metronome PRIVATE "${PROJECT_SOURCE_DIR}/src")

add_custom_target(flash avrdude -c usbasp -p ${MCU} -U flash:w:${PROJECT_NAME}.elf)
