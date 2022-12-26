# use command: make -f Makefile FILENAME=myfilename

# Filename name must be provided as command arguments
FILENAME = nofilenameprovided
MCU = atmega328p
CPUSPEED = 16000000

# Port on which arduino is connected. This can be checked in computer's manage -> devices
COMPORT = com4

# ${FILENAME}:
# 	avr-gcc -Os -DF_CPU=${CPUSPEED} -mmcu=${MCU} -c -o ${FILENAME}.o src/${FILENAME}.c
# 	avr-gcc -o ${FILENAME}.bin ${FILENAME}.o
# 	avr-objcopy -O ihex -R .eeprom ${FILENAME}.bin ${FILENAME}.hex
# 	avrdude -F -V -c arduino -p ${MCU} -P ${COMPORT} -b 115200 -U flash:w:${FILENAME}.hex
# 	make clean

# For cpp file	
# ${FILENAME}:
# 	avr-gcc -Os -DF_CPU=${CPUSPEED} -mmcu=${MCU} -c -o ${FILENAME}.o ${FILENAME}.cpp
# 	avr-gcc -o ${FILENAME}.bin ${FILENAME}.o
# 	avr-objcopy -O ihex -R .eeprom ${FILENAME}.bin ${FILENAME}.hex
# 	avrdude -F -V -c arduino -p ${MCU} -P ${COMPORT} -b 115200 -U flash:w:${FILENAME}.hex
# 	make clean

${FILENAME}:
	avr-gcc -Wall -g -Os -DF_CPU=${CPUSPEED} -mmcu=${MCU} -o ${FILENAME}.bin src/${FILENAME}.c 
	avr-size -C ${FILENAME}.bin
#	avr-objcopy -j .text -j .data -O ihex ${FILENAME}.bin ${FILENAME}.hex
	avr-objcopy -O ihex ${FILENAME}.bin ${FILENAME}.hex
	avrdude -F -V -c arduino -p ${MCU} -P ${COMPORT} -b 115200 -U flash:w:${FILENAME}.hex
#	avrdude -p ${MCU} -c arduino -P ${COMPORT} -U flash:w:${FILENAME}.hex:i
	make clean

clean:
	del ${FILENAME}.hex
	del ${FILENAME}.o
	del ${FILENAME}.bin
#	del ${FILENAME}.elf