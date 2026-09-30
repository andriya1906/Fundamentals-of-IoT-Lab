# Experiment 9: STM32 UART Command Controlled LED

## Objective

Configure UART communication on the STM32F103C8T6 Blue Pill using STM32CubeMX and HAL libraries. Establish serial communication with a PC terminal, implement character transmission and reception, and develop a UART-based command interface to control the onboard LED.

## Hardware Used

* STM32F103C8T6 Blue Pill Development Board
* ST-Link Programmer
* USB-to-TTL Converter
* Breadboard
* Jumper Wires
* LED
* Resistor
* PC

## Software Used

* STM32CubeMX
* Keil MDK
* PuTTY

## Key Functions

| **Task** | **Function**                                           |
| -------- | ------------------------------------------------------ |
| 9A       | Basic UART character transmission and receive-and-echo |
| 9B       | UART command-based LED control                         |

## UART Commands

| **Command**  | **Function**                           |
| ------------ | -------------------------------------- |
| `LED ON`     | Turn the LED ON                        |
| `LED OFF`    | Turn the LED OFF                       |
| `LED TOGGLE` | Toggle the LED and enter blinking mode |

## Features

* STM32 UART configuration using HAL
* Character transmission and reception
* Receive-and-echo functionality
* UART-based command interface
* Command-controlled LED operation
* LED blinking using UART command
* Use of `\r` (Carriage Return) and `\n` (Line Feed)
* Serial communication with a PC terminal using PuTTY
* STM32 HAL-based UART and GPIO control

## Files

* `task1.c` – Basic UART character transmission
* `task2.c` – UART receive-and-echo
* `task3.c` – UART command-based LED control
