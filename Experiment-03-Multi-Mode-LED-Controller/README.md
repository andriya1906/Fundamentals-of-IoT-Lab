# Experiment 3: Multi-Mode LED Pattern Generator Using GPIO and Push Button

## Objective

To develop a register-level GPIO controller using the AT89S52 microcontroller that controls four LEDs through four different operating modes. A single push button is used to switch between the modes, with software debouncing to ensure one state transition per button press.

---

## Hardware Required

- AT89S52 Development Board
- 4 LEDs
- 4 Resistors
- 1 Push Button
- USB Programmer
- Jumper Wires
- Breadboard

---

## Software Used

- Keil µVision
- ProgISP

---

## Modes Implemented

### Mode 0 – Running LED
The LEDs glow one after another in the sequence:

LED1 → LED2 → LED3 → LED4

---

### Mode 1 – Binary Counter
The four LEDs display the binary count from:

0000 → 1111

---

### Mode 2 – Alternating Pattern
The LEDs alternate between:

1010 ↔ 0101

---

### Mode 3 – All LED Flash
All four LEDs blink together.

---

## Button Logic

- A single push button is used to switch between modes.
- Each valid button press increments the mode counter.
- Software debouncing is implemented by waiting until the button is released before accepting another button press.
- The button is polled during the delay routine, allowing the current mode to terminate immediately after a button press.

---

## Concepts Used

- Register-level GPIO Programming
- Embedded C
- Polling
- Software Debouncing
- State Machine

---

## Files

- `main.c` – Embedded C source code
- `main.hex` – Compiled HEX file

---
