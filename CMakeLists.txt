project(avr_metronome)
cmake_minimum_required(VERSION 3.3)

set(CMAKE_C_COMPILER "/usr/bin/avr-gcc")
set(CMAKE_C_STANDARD 17)
set(F_CPU 20000000UL)
set(MCU "atmega328p")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -O3 -mmcu=${MCU} -DF_CPU=${F_CPU} -flto")
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS)
set(LFUSE 0xdf)
set(HFUSE 0xd1)
set(EFUSE 0xff)

add_executable(avr_metronome
	"${PROJECT_SOURCE_DIR}/src/encoder_control.c"
	"${PROJECT_SOURCE_DIR}/src/lcd_control.c"
	"${PROJECT_SOURCE_DIR}/src/beep.c"
	"${PROJECT_SOURCE_DIR}/src/metronome.c"
	"${PROJECT_SOURCE_DIR}/src/uart_com.c"
)

target_link_libraries(avr_metronome)
target_include_directories(avr_metronome PRIVATE "${PROJECT_SOURCE_DIR}/src")

add_custom_target(prog avrdude ${CMAKE_BUILD_DIR}/${EXECUTABLE_OUTPUT_PATH} 
	-c usbasp -p ${MCU} -U flash:w:${PROJECT_NAME})
add_custom_target(prog_fuse avrdude ${CMAKE_BUILD_DIR}/${EXECUTABLE_OUTPUT_PATH} 
	-c usbasp -p ${MCU} lfuse:w:${LFUSE}:m hfuse:w:${HFUSE}:m efuse:w:${EFUSE}:m)
