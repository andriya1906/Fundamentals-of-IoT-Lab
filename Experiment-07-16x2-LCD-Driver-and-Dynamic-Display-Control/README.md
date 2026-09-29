# Experiment 7: 16×2 LCD Driver and Dynamic Display Control

## Objective

Design and implement a 4-bit LCD interface using the AT89S52 microcontroller. Initialize a 16×2 character LCD, display characters and strings, position the cursor, and control character movement using a keypad.

## Hardware Used

- AT89S52 Development Board
- 16×2 Character LCD
- 4×4 Matrix Keypad

## Software Used

- Keil µVision
- ProgISP

## Key Functions

| **Task** | **Function** |
| -------- | ------------ |
| 1        | LCD initialization and basic display control |
| 2        | LCD driver functions, cursor positioning, string and number display |
| 3        | Keypad-controlled movement of a character on the LCD |

## Features

- Register-level LCD programming
- 4-bit LCD communication
- 16×2 LCD initialization and configuration
- LCD command and data handling
- Cursor positioning using row and column
- String and integer display
- 4×4 keypad scanning
- Up, down, left, and right character movement
- Boundary checking for character movement

## Files

- `task1.c` – Basic LCD initialization and display control
- `task2.c` – LCD driver with cursor positioning, string and number display
- `task3.c` – Keypad-controlled character movement on the LCD
