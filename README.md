# Bare Metal STM32F103C8T6

This project demonstrates **a full bare-metal firmware** for the STM32F103C8T6 (Blue Pill)

The goal is to understand low-level embedded system concepts, including
- Startup code
- Linker script
- Memory layout (.text, .data,.bss)
- Vector table
- Direct register manipulation

# Features
- Custom startup code (Reset Handler, Default Handler, vector table)
- Custom linker script
- Blinking LED on PC13

# Hardware
- STM32F103C8T6 (Blue Pill)
- ST-Link V2

<img width="225" height="225" alt="image" src="https://github.com/user-attachments/assets/47743553-0887-4571-a167-99ca0b360aed" />
<img width="259" height="194" alt="image" src="https://github.com/user-attachments/assets/a4bc4b48-2018-4636-ba7f-8551d7fe736a" />

# Project Structure
├── main.c # Application code (LED blink)

├── stm32f103_startup.c # Startup code + vector table

├── stm32f103_ls.ld # Linker script

├── Makefile # Build system

├── final.elf # Output ELF (after build)

# How to build this project

You will need GNU Embedded Toolchain and GNU Make

Open on the terminal where the files at and run
'''
make
'''

We will get an output file : final.elf

# Flash to the MCU

We need to connect 4 pins on the ST LINK V2 and the MCU
- 3V3
- GND
- SWDIO
- SWCLK

<img width="1350" height="751" alt="image" src="https://github.com/user-attachments/assets/ba1d7b22-c070-44e1-84bf-d37cdfc21694" />


We need to install STM32CubeProgrammer
- Load the .elf file
- Download

You should see the LED on PC13 blinking (which is onboard)

# How it works
## 1.Reset Handler
- **.data** is copied from Flash to SRAM
- **.bss** is zerod
- main() is called

## 2. Memory Layout
We have a custom layout (no heap because there is no standard lib)

**Flash**
- .isr_vector (vector table)
- .text (code or instructions)
- .rodata (read-only data)

**RAM**
- .data (initialized globals)
- .bss  (zerod-initialized globals)
- .stack (grows downward, the top of the stack is the end of SRAM)

## 3. Blinking LED
- Direct access to register using struct

# Resources
[How to build bare-metal project from ground up](https://www.youtube.com/playlist?list=PLERTijJOmYrDiiWd10iRHY0VRHdJwUH4g)

[STM32F10x Reference Manual](https://www.st.com/resource/en/reference_manual/rm0008-stm32f101xx-stm32f102xx-stm32f103xx-stm32f105xx-and-stm32f107xx-advanced-armbased-32bit-mcus-stmicroelectronics.pdf)







