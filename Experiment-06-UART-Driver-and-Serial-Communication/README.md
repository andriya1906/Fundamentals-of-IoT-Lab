# Experiment 6: UART Driver and Serial Communication

## Objective

Develop a UART driver for the AT89S52 microcontroller to establish serial communication with a PC terminal using a USB-to-TTL serial interface. Configure the UART for 9600-8-N-1 communication and implement character transmission, reception, and echo.

## Hardware Used

- AT89S52 Development Board
- USB-to-TTL Converter
- PC

## Software Used

- Keil µVision
- PuTTY
- ProgISP

## Key Functions

| **Task** | **Function** |
| -------- | ------------ |
| 1        | UART initialization and continuous character transmission |
| 2        | UART character reception and echo |

## Features

- Register-level UART configuration
- 8-bit asynchronous UART communication
- 9600 baud rate with 1 stop bit and no parity
- Timer 1 Mode 2 used for baud-rate generation
- Continuous character transmission from the 8051
- Character reception from a PC terminal
- UART echo for interactive serial communication
- USB-to-TTL interface for PC communication

## Files

- `task1.c` – UART initialization and continuous character transmission
- `task2.c` – UART character reception and echo
