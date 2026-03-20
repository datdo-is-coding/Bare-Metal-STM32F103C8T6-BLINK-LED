CC  = arm-none-eabi-gcc
MACH=cortex-m3
CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu11 -O0
LDFLAGS = -nostdlib -T stm32f103_ls.ld -Wl,-Map=final.map
all: main.o stm32f103_startup.o final.elf

main.o : main.c
	$(CC) $(CFLAGS) -o $@ $^

stm32f103_startup.o : stm32f103_startup.c
	$(CC) $(CFLAGS) -o $@ $^

final.elf: main.o stm32f103_startup.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -rf *.o *.elf
