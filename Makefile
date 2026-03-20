CC  = arm-none-eabi-gcc
MACH=cortex-m3
CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu11 -O0

all: main.o stm32f103_startup.o

main.o : main.c
	$(CC) $(CFLAGS) -o $@ $^

stm32f103_startup.o : stm32f103_startup.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf *.o *.elf
