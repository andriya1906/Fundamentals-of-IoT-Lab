# Experiment 4: Matrix Keypad Interface with Seven-Segment Display and LED Control

## Objective

Design and implement a Human-Machine Interface (HMI) using the AT89S52 microcontroller. Interface a 4×4 matrix keypad, seven-segment display, and four LEDs to perform different LED operations based on the key pressed.

## Hardware Used

- AT89S52 Development Board
- 4×4 Matrix Keypad
- Seven-Segment Display (Common Cathode)
- 4 LEDs
- USB Programmer

## Software Used

- Keil µVision
- ProgISP

## Key Functions

| Key | Function |
|-----|----------|
| 0 | Reset system / Turn OFF all LEDs |
| 1 | Display 1 and Turn ON LED 1 |
| 2 | Display 2 and Turn ON LED 2 |
| 3 | Display 3 and Turn ON LED 3 |
| 4 | Display 4 and Turn ON LED 4 |
| 5 | Display 5 and Running LED Pattern |
| 6 | Display 6 and Alternate LED Pattern |
| 7 | Display 7 and Binary Counter (0–15) |
| 8 | Display 8 and Blink All LEDs |
| 9 | Display 9 and Turn OFF all LEDs |

## Features

- Register-level GPIO programming
- Matrix keypad scanning using row-column technique
- Seven-segment display interfacing
- Multiple LED operating modes
- Continuous keypad polling for responsive mode switching
- Software delay with real-time key detection

## Files

- `main.c` – Embedded C source code
- `main.hex` – Compiled HEX file
