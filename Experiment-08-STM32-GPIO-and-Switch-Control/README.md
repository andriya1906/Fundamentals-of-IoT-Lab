# Experiment 8: STM32 GPIO Bring-Up and Switch-Controlled LED

## Objective

Interface a push-button switch and LED with the STM32F103C8T6 Blue Pill development board. Configure GPIO input/output and implement switch-controlled LED operation, event-based toggling, and short-press/long-press detection using STM32 HAL libraries.

## Hardware Used

* STM32F103C8T6 Blue Pill Development Board
* ST-Link
* Push-Button Switch
* LED
* Resistor
* Jumper Wires
* Bread Board

## Software Used

* STM32CubeMX
* Keil MDK

## Key Functions

| **Task** | **Function**                                    |
| -------- | ----------------------------------------------- |
| 8A       | GPIO input/output and switch-controlled LED     |
| 8B       | Event-based LED toggling with switch debouncing |
| 8C       | Short-press and long-press detection            |

## Features

* STM32 GPIO configuration and bring-up
* Push-button input and LED output
* Switch-controlled LED operation
* Event-based LED toggling
* Software switch-bounce handling
* Short-press detection (< 1 second)
* Long-press detection (≥ 1 second)
* Continuous LED blinking mode
* Non-blocking press-duration measurement using `HAL_GetTick()`
* STM32 HAL-based GPIO control

## Files

* `task1.c` – GPIO input/output and switch-controlled LED
* `task2.c` – Event-based LED toggling with debounce
* `task3.c` – Short-press and long-press detection
