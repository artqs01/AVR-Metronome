EESchema Schematic File Version 5
EELAYER 36 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
Comment5 ""
Comment6 ""
Comment7 ""
Comment8 ""
Comment9 ""
$EndDescr
Connection ~ 3100 3050
Connection ~ 3100 3250
Connection ~ 3900 2150
Connection ~ 3900 2300
Connection ~ 3900 2700
Connection ~ 4450 2300
Connection ~ 4450 2700
Connection ~ 5000 3450
Connection ~ 5000 3550
Connection ~ 5000 3650
Connection ~ 5000 3750
Connection ~ 5000 3950
Connection ~ 5000 4350
Connection ~ 5100 2300
Connection ~ 5700 2100
Connection ~ 5700 2300
Wire Wire Line
	2300 850  2300 950 
Wire Wire Line
	2400 850  2400 950 
Wire Wire Line
	2800 1450 2850 1450
Wire Wire Line
	2950 2150 2950 2500
Wire Wire Line
	2950 2150 3900 2150
Wire Wire Line
	2950 2700 3900 2700
Wire Wire Line
	2950 3050 2950 3100
Wire Wire Line
	2950 3250 2950 3200
Wire Wire Line
	2950 3900 4900 3900
Wire Wire Line
	2950 4800 3050 4800
Wire Wire Line
	3000 2300 3000 2600
Wire Wire Line
	3000 2300 3900 2300
Wire Wire Line
	3000 2600 2950 2600
Wire Wire Line
	3050 4800 3050 5750
Wire Wire Line
	3100 3050 2950 3050
Wire Wire Line
	3100 3050 3250 3050
Wire Wire Line
	3100 3250 2950 3250
Wire Wire Line
	3100 3250 3250 3250
Wire Wire Line
	3450 3050 3650 3050
Wire Wire Line
	3450 3250 3550 3250
Wire Wire Line
	3900 1800 4000 1800
Wire Wire Line
	3900 1950 3900 1800
Wire Wire Line
	3900 2300 4050 2300
Wire Wire Line
	3900 2700 4050 2700
Wire Wire Line
	4050 2150 3900 2150
Wire Wire Line
	4150 4200 4550 4200
Wire Wire Line
	4150 4300 4550 4300
Wire Wire Line
	4150 4400 4550 4400
Wire Wire Line
	4150 4500 4550 4500
Wire Wire Line
	4150 4600 4550 4600
Wire Wire Line
	4250 2150 5100 2150
Wire Wire Line
	4250 2300 4450 2300
Wire Wire Line
	4250 2700 4450 2700
Wire Wire Line
	4450 2100 4450 2300
Wire Wire Line
	4450 2400 4400 2400
Wire Wire Line
	4450 2700 4450 2500
Wire Wire Line
	4900 3900 4900 4050
Wire Wire Line
	4950 3800 2950 3800
Wire Wire Line
	4950 3850 4950 3800
Wire Wire Line
	5000 2850 5000 3450
Wire Wire Line
	5000 3450 5000 3550
Wire Wire Line
	5000 3550 5000 3650
Wire Wire Line
	5000 3650 5000 3750
Wire Wire Line
	5000 3750 5000 3950
Wire Wire Line
	5000 3950 5000 4350
Wire Wire Line
	5000 4350 5000 4500
Wire Wire Line
	5000 4350 5300 4350
Wire Wire Line
	5100 2300 5050 2300
Wire Wire Line
	5100 2300 5100 2150
Wire Wire Line
	5150 2500 5050 2500
Wire Wire Line
	5300 2850 5000 2850
Wire Wire Line
	5300 3450 5000 3450
Wire Wire Line
	5300 3550 5000 3550
Wire Wire Line
	5300 3650 5000 3650
Wire Wire Line
	5300 3750 5000 3750
Wire Wire Line
	5300 3850 4950 3850
Wire Wire Line
	5300 3950 5000 3950
Wire Wire Line
	5300 4050 4900 4050
Wire Wire Line
	5300 4250 5250 4250
Wire Wire Line
	5400 2100 4450 2100
Wire Wire Line
	5400 2300 5100 2300
Wire Wire Line
	5400 2700 4450 2700
Wire Wire Line
	5600 2100 5700 2100
Wire Wire Line
	5600 2300 5700 2300
Wire Wire Line
	5700 1900 5700 2100
Wire Wire Line
	5700 2100 5700 2300
Wire Wire Line
	5700 2300 5700 2700
Wire Wire Line
	5700 2700 5600 2700
Text Label 2200 950  2    50   ~ 0
RST
Text Label 2300 850  2    50   ~ 0
SCK
Text Label 2400 850  0    50   ~ 0
MOSI
Text Label 2500 950  0    50   ~ 0
MISO
Text Label 2950 2800 0    50   ~ 0
MOSI
Text Label 2950 2900 0    50   ~ 0
MISO
Text Label 2950 3000 0    50   ~ 0
SCK
Text Label 2950 3400 0    50   ~ 0
D4
Text Label 2950 3500 0    50   ~ 0
D5
Text Label 2950 3600 0    50   ~ 0
D6
Text Label 2950 3700 0    50   ~ 0
D7
Text Label 2950 4000 0    50   ~ 0
RST
Text Label 5300 3050 2    50   ~ 0
D7
Text Label 5300 3150 2    50   ~ 0
D6
Text Label 5300 3250 2    50   ~ 0
D5
Text Label 5300 3350 2    50   ~ 0
D4
Text Label 5300 3450 2    50   ~ 0
D3
Text Label 5300 3550 2    50   ~ 0
D2
Text Label 5300 3650 2    50   ~ 0
D1
Text Label 5300 3750 2    50   ~ 0
D0
Text Label 5300 3850 2    50   ~ 0
E
Text Label 5300 3950 2    50   ~ 0
RW
Text Label 5300 4050 2    50   ~ 0
RS
Text Label 5300 4150 2    50   ~ 0
V0
$Comp
L avr_metronome_1-rescue:+5V-power #PWR?
U 1 1 615B2040
P 2350 2200
F 0 "#PWR?" H 2350 2050 50  0001 C CNN
F 1 "+5V" H 2365 2373 50  0000 C CNN
F 2 "" H 2350 2200 50  0001 C CNN
F 3 "" H 2350 2200 50  0001 C CNN
	1    2350 2200
	1    0    0    -1  
$EndComp
$Comp
L avr_metronome_1-rescue:+5V-power #PWR?
U 1 1 617C34FE
P 2850 1450
F 0 "#PWR?" H 2850 1300 50  0001 C CNN
F 1 "+5V" H 2865 1623 50  0000 C CNN
F 2 "" H 2850 1450 50  0001 C CNN
F 3 "" H 2850 1450 50  0001 C CNN
	1    2850 1450
	1    0    0    -1  
$EndComp
$Comp
L avr_metronome_1-rescue:+5V-power #PWR?
U 1 1 615C6D04
P 5250 4250
F 0 "#PWR?" H 5250 4100 50  0001 C CNN
F 1 "+5V" V 5300 4300 50  0000 L CNN
F 2 "" H 5250 4250 50  0001 C CNN
F 3 "" H 5250 4250 50  0001 C CNN
	1    5250 4250
	0    -1   -1   0   
$EndComp
$Comp
L avr_metronome_1-rescue:+5V-power #PWR?
U 1 1 615F68F3
P 5300 2950
F 0 "#PWR?" H 5300 2800 50  0001 C CNN
F 1 "+5V" V 5300 3050 50  0000 L CNN
F 2 "" H 5300 2950 50  0001 C CNN
F 3 "" H 5300 2950 50  0001 C CNN
	1    5300 2950
	0    -1   -1   0   
$EndComp
$Comp
L avr_metronome_1-rescue:+5V-power #PWR?
U 1 1 616140C8
P 5700 1900
F 0 "#PWR?" H 5700 1750 50  0001 C CNN
F 1 "+5V" H 5715 2073 50  0000 C CNN
F 2 "" H 5700 1900 50  0001 C CNN
F 3 "" H 5700 1900 50  0001 C CNN
	1    5700 1900
	1    0    0    -1  
$EndComp
$Comp
L avr_metronome_1-rescue:GND-power #PWR?
U 1 1 617C16E2
P 1900 1450
F 0 "#PWR?" H 1900 1200 50  0001 C CNN
F 1 "GND" H 1905 1277 50  0000 C CNN
F 2 "" H 1900 1450 50  0001 C CNN
F 3 "" H 1900 1450 50  0001 C CNN
	1    1900 1450
	1    0    0    -1  
$EndComp
$Comp
L avr_metronome_1-rescue:GND-power #PWR?
U 1 1 615A13B9
P 2350 5200
F 0 "#PWR?" H 2350 4950 50  0001 C CNN
F 1 "GND" H 2355 5027 50  0000 C CNN
F 2 "" H 2350 5200 50  0001 C CNN
F 3 "" H 2350 5200 50  0001 C CNN
	1    2350 5200
	1    0    0    -1  
$EndComp
$Comp
L avr_metronome_1-rescue:GND-power #PWR?
U 1 1 61726169
P 3050 5950
F 0 "#PWR?" H 3050 5700 50  0001 C CNN
F 1 "GND" H 3055 5777 50  0000 C CNN
F 2 "" H 3050 5950 50  0001 C CNN
F 3 "" H 3050 5950 50  0001 C CNN
	1    3050 5950
	1    0    0    -1  
$EndComp
$Comp
L avr_metronome_1-rescue:GND-power #PWR?
U 1 1 6158CC34
P 3550 3250
F 0 "#PWR?" H 3550 3000 50  0001 C CNN
F 1 "GND" H 3555 3077 50  0000 C CNN
F 2 "" H 3550 3250 50  0001 C CNN
F 3 "" H 3550 3250 50  0001 C CNN
	1    3550 3250
	1    0    0    -1  
$EndComp
$Comp
L avr_metronome_1-rescue:GND-power #PWR?
U 1 1 6158B6E4
P 3650 3050
F 0 "#PWR?" H 3650 2800 50  0001 C CNN
F 1 "GND" H 3655 2877 50  0000 C CNN
F 2 "" H 3650 3050 50  0001 C CNN
F 3 "" H 3650 3050 50  0001 C CNN
	1    3650 3050
	1    0    0    -1  
$EndComp
$Comp
L avr_metronome_1-rescue:GND-power #PWR?
U 1 1 616564B1
P 3900 2500
F 0 "#PWR?" H 3900 2250 50  0001 C CNN
F 1 "GND" H 4000 2400 50  0000 C CNN
F 2 "" H 3900 2500 50  0001 C CNN
F 3 "" H 3900 2500 50  0001 C CNN
	1    3900 2500
	1    0    0    -1  
$EndComp
$Comp
L avr_metronome_1-rescue:GND-power #PWR?
U 1 1 616534E5
P 3900 2900
F 0 "#PWR?" H 3900 2650 50  0001 C CNN
F 1 "GND" H 4000 2800 50  0000 C CNN
F 2 "" H 3900 2900 50  0001 C CNN
F 3 "" H 3900 2900 50  0001 C CNN
	1    3900 2900
	1    0    0    -1  
$EndComp
$Comp
L avr_metronome_1-rescue:GND-power #PWR?
U 1 1 616A6F65
P 4000 1800
F 0 "#PWR?" H 4000 1550 50  0001 C CNN
F 1 "GND" H 4100 1700 50  0000 C CNN
F 2 "" H 4000 1800 50  0001 C CNN
F 3 "" H 4000 1800 50  0001 C CNN
	1    4000 1800
	1    0    0    -1  
$EndComp
$Comp
L avr_metronome_1-rescue:GND-power #PWR?
U 1 1 61609C05
P 4400 2400
F 0 "#PWR?" H 4400 2150 50  0001 C CNN
F 1 "GND" H 4300 2300 50  0000 C CNN
F 2 "" H 4400 2400 50  0001 C CNN
F 3 "" H 4400 2400 50  0001 C CNN
	1    4400 2400
	1    0    0    -1  
$EndComp
$Comp
L avr_metronome_1-rescue:GND-power #PWR?
U 1 1 615C423F
P 5000 4500
F 0 "#PWR?" H 5000 4250 50  0001 C CNN
F 1 "GND" H 5005 4327 50  0000 C CNN
F 2 "" H 5000 4500 50  0001 C CNN
F 3 "" H 5000 4500 50  0001 C CNN
	1    5000 4500
	1    0    0    -1  
$EndComp
$Comp
L avr_metronome_1-rescue:GND-power #PWR?
U 1 1 6160B0AD
P 5150 2500
F 0 "#PWR?" H 5150 2250 50  0001 C CNN
F 1 "GND" H 5250 2400 50  0000 C CNN
F 2 "" H 5150 2500 50  0001 C CNN
F 3 "" H 5150 2500 50  0001 C CNN
	1    5150 2500
	1    0    0    -1  
$EndComp
$Comp
L avr_metronome_1-rescue:R_Small-Device R?
U 1 1 616E8238
P 4150 2150
F 0 "R?" V 4050 2100 50  0000 C CNN
F 1 "10k" V 4050 2250 50  0000 C CNN
F 2 "" H 4150 2150 50  0001 C CNN
F 3 "~" H 4150 2150 50  0001 C CNN
	1    4150 2150
	0    1    1    0   
$EndComp
$Comp
L avr_metronome_1-rescue:R_Small-Device R?
U 1 1 616EB6A5
P 4150 2300
F 0 "R?" V 4250 2250 50  0000 C CNN
F 1 "10k" V 4250 2400 50  0000 C CNN
F 2 "" H 4150 2300 50  0001 C CNN
F 3 "~" H 4150 2300 50  0001 C CNN
	1    4150 2300
	0    1    1    0   
$EndComp
$Comp
L avr_metronome_1-rescue:R_Small-Device R?
U 1 1 616EDB8B
P 4150 2700
F 0 "R?" V 4250 2650 50  0000 C CNN
F 1 "10k" V 4250 2800 50  0000 C CNN
F 2 "" H 4150 2700 50  0001 C CNN
F 3 "~" H 4150 2700 50  0001 C CNN
	1    4150 2700
	0    1    1    0   
$EndComp
$Comp
L avr_metronome_1-rescue:R_Small-Device R?
U 1 1 6170BE6E
P 5500 2100
F 0 "R?" V 5400 2050 50  0000 C CNN
F 1 "10k" V 5400 2200 50  0000 C CNN
F 2 "" H 5500 2100 50  0001 C CNN
F 3 "~" H 5500 2100 50  0001 C CNN
	1    5500 2100
	0    1    1    0   
$EndComp
$Comp
L avr_metronome_1-rescue:R_Small-Device R?
U 1 1 6170C6B4
P 5500 2300
F 0 "R?" V 5400 2250 50  0000 C CNN
F 1 "10k" V 5400 2400 50  0000 C CNN
F 2 "" H 5500 2300 50  0001 C CNN
F 3 "~" H 5500 2300 50  0001 C CNN
	1    5500 2300
	0    1    1    0   
$EndComp
$Comp
L avr_metronome_1-rescue:R_Small-Device R?
U 1 1 6170CC48
P 5500 2700
F 0 "R?" V 5400 2650 50  0000 C CNN
F 1 "10k" V 5400 2800 50  0000 C CNN
F 2 "" H 5500 2700 50  0001 C CNN
F 3 "~" H 5500 2700 50  0001 C CNN
	1    5500 2700
	0    1    1    0   
$EndComp
$Comp
L avr_metronome_1-rescue:Crystal_Small-Device Y1
U 1 1 615696F2
P 3100 3150
F 0 "Y1" V 2900 3100 50  0000 L CNN
F 1 "20 MHz" V 3100 3250 50  0000 L CNN
F 2 "" H 3100 3150 50  0001 C CNN
F 3 "~" H 3100 3150 50  0001 C CNN
	1    3100 3150
	0    1    -1   0   
$EndComp
$Comp
L avr_metronome_1-rescue:C_Small-Device C?
U 1 1 61579F46
P 3350 3050
F 0 "C?" V 3100 3050 50  0000 C CNN
F 1 "22p" V 3200 3050 50  0000 C CNN
F 2 "" H 3350 3050 50  0001 C CNN
F 3 "~" H 3350 3050 50  0001 C CNN
	1    3350 3050
	0    1    1    0   
$EndComp
$Comp
L avr_metronome_1-rescue:C_Small-Device C?
U 1 1 6157B363
P 3350 3250
F 0 "C?" V 3450 3250 50  0000 C CNN
F 1 "22p" V 3550 3250 50  0000 C CNN
F 2 "" H 3350 3250 50  0001 C CNN
F 3 "~" H 3350 3250 50  0001 C CNN
	1    3350 3250
	0    1    1    0   
$EndComp
$Comp
L avr_metronome_1-rescue:C_Small-Device C?
U 1 1 61641DF9
P 3900 2050
F 0 "C?" H 4050 2000 50  0000 C CNN
F 1 "100n" H 4050 2100 50  0000 C CNN
F 2 "" H 3900 2050 50  0001 C CNN
F 3 "~" H 3900 2050 50  0001 C CNN
	1    3900 2050
	-1   0    0    1   
$EndComp
$Comp
L avr_metronome_1-rescue:C_Small-Device C?
U 1 1 6164103F
P 3900 2400
F 0 "C?" H 4050 2400 50  0000 C CNN
F 1 "100n" H 4050 2500 50  0000 C CNN
F 2 "" H 3900 2400 50  0001 C CNN
F 3 "~" H 3900 2400 50  0001 C CNN
	1    3900 2400
	-1   0    0    1   
$EndComp
$Comp
L avr_metronome_1-rescue:C_Small-Device C?
U 1 1 616372B5
P 3900 2800
F 0 "C?" H 4050 2750 50  0000 C CNN
F 1 "100n" H 4050 2850 50  0000 C CNN
F 2 "" H 3900 2800 50  0001 C CNN
F 3 "~" H 3900 2800 50  0001 C CNN
	1    3900 2800
	-1   0    0    1   
$EndComp
$Comp
L avr_metronome_1-rescue:R_POT_Small-Device RV?
U 1 1 6172451F
P 3050 5850
F 0 "RV?" H 2950 5900 50  0000 R CNN
F 1 "10k" H 2950 5800 50  0000 R CNN
F 2 "" H 3050 5850 50  0001 C CNN
F 3 "~" H 3050 5850 50  0001 C CNN
	1    3050 5850
	-1   0    0    1   
$EndComp
$Comp
L avr_metronome_1-rescue:SW_MEC_5G-Switch SW2
U 1 1 61879965
P 3950 4200
F 0 "SW2" H 4150 4250 50  0000 C CNN
F 1 "UP" H 4300 4250 50  0000 C CNN
F 2 "" H 3950 4400 50  0001 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=488" H 3950 4400 50  0001 C CNN
	1    3950 4200
	1    0    0    -1  
$EndComp
$Comp
L avr_metronome_1-rescue:SW_MEC_5G-Switch SW3
U 1 1 618835C8
P 3950 4300
F 0 "SW3" H 4150 4350 50  0000 C CNN
F 1 "DOWN" H 4350 4350 50  0000 C CNN
F 2 "" H 3950 4500 50  0001 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=488" H 3950 4500 50  0001 C CNN
	1    3950 4300
	1    0    0    -1  
$EndComp
$Comp
L avr_metronome_1-rescue:SW_MEC_5G-Switch SW4
U 1 1 61883AFD
P 3950 4400
F 0 "SW4" H 4150 4450 50  0000 C CNN
F 1 "LEFT" H 4350 4450 50  0000 C CNN
F 2 "" H 3950 4600 50  0001 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=488" H 3950 4600 50  0001 C CNN
	1    3950 4400
	1    0    0    -1  
$EndComp
$Comp
L avr_metronome_1-rescue:SW_MEC_5G-Switch SW5
U 1 1 61884102
P 3950 4500
F 0 "SW5" H 4150 4550 50  0000 C CNN
F 1 "RIGHT" H 4350 4550 50  0000 C CNN
F 2 "" H 3950 4700 50  0001 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=488" H 3950 4700 50  0001 C CNN
	1    3950 4500
	1    0    0    -1  
$EndComp
$Comp
L avr_metronome_1-rescue:SW_MEC_5G-Switch SW6
U 1 1 61884700
P 3950 4600
F 0 "SW6" H 4150 4650 50  0000 C CNN
F 1 "SEL" H 4300 4650 50  0000 C CNN
F 2 "" H 3950 4800 50  0001 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=488" H 3950 4800 50  0001 C CNN
	1    3950 4600
	1    0    0    -1  
$EndComp
$Comp
L avr_metronome_1-rescue:Rotary_Encoder_Switch-Device SW1
U 1 1 61601DA9
P 4750 2400
F 0 "SW1" H 4750 2850 50  0000 C CNN
F 1 "Tempo_Encoder_Switch" H 4800 2750 50  0000 C CNN
F 2 "" H 4600 2560 50  0001 C CNN
F 3 "~" H 4750 2660 50  0001 C CNN
	1    4750 2400
	1    0    0    -1  
$EndComp
$Comp
L avr_metronome_1-rescue:Conn_01x16-Connector_Generic J1
U 1 1 615B5463
P 5500 3550
F 0 "J1" H 5450 2650 50  0000 L CNN
F 1 "Conn_01x16" H 5250 4400 50  0000 L CNN
F 2 "" H 5500 3550 50  0001 C CNN
F 3 "~" H 5500 3550 50  0001 C CNN
	1    5500 3550
	1    0    0    -1  
$EndComp
$Comp
L avr_metronome_1-rescue:AVR-ISP-6-Connector J2
U 1 1 617A7C62
P 2300 1350
F 0 "J2" V 1925 1400 50  0000 C CNN
F 1 "AVR-ISP-6" V 1834 1400 50  0000 C CNN
F 2 "" V 2050 1400 50  0001 C CNN
F 3 " ~" H 1025 800 50  0001 C CNN
	1    2300 1350
	0    1    -1   0   
$EndComp
$Comp
L avr_metronome_1-rescue:ATmega328P-AU-MCU_Microchip_ATmega U1
U 1 1 615635F3
P 2350 3700
F 0 "U1" H 1950 5300 50  0000 C CNN
F 1 "ATmega328P-AU" H 1950 5200 50  0000 C CNN
F 2 "Package_QFP:TQFP-32_7x7mm_P0.8mm" H 2350 3700 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 2350 3700 50  0001 C CNN
	1    2350 3700
	1    0    0    -1  
$EndComp
$EndSCHEMATC
