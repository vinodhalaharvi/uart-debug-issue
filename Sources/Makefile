CFLAGS=-ggdb -Wall 

all: io

sdram: sdram.o

mcg: mcg.o

lcdc: lcdc.o lcdcdriver.o

lcdcdriver: lcdcdriver.o

uart: delay.o  uartdriver.o uart.o

uartdriver: uartdriver.o

lcdc: lcdc.o

mymalloc: mymalloc.o

stringutils: stringutils.o mymalloc.o

common: common.o

lcdcConsole: lcdcConsole.o 

profont: profont.o

svc: svc.o

main: io.o uart.o lcdc.o stringutils.o common.o delay.o uartdriver.o lcdcdriver.o mymalloc.o lcdcConsole.o profont.o svc.o led.o leddriver.o pushbutton.o pushbuttondriver.o capacitivepads.o capacitivepadsdriver.o thermistor.o thermistordriver.o potentiometer.o potentiometerdriver.o 

run: main
	./main

clean:
	rm -f *.o
	rm -f io
