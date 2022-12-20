# use command: make -f Makefile FILENAME=myfilename

# Filename name must be provided as command arguments
FILENAME = nofilenameprovided
MCU = atmega328p
CPUSPEED = 16000000UL

# Port on which arduino is connected. This can be checked in computer's manage -> devices
COMPORT = com4

${FILENAME}:
	avr-gcc -Os -DF_CPU=${CPUSPEED} -mmcu=${MCU} -c -o ${FILENAME}.o ${FILENAME}.c
	avr-gcc -o ${FILENAME}.bin ${FILENAME}.o
	avr-objcopy -O ihex -R .eeprom ${FILENAME}.bin ${FILENAME}.hex
	avrdude -F -V -c arduino -p ${MCU} -P ${COMPORT} -b 115200 -U flash:w:${FILENAME}.hex
	make clean
	
clean:
	del ${FILENAME}.hex
	del ${FILENAME}.o
	del ${FILENAME}.bin