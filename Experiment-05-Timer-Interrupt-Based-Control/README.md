# Experiment 5: Hardware Timer-Based LED, PWM, and Stepper Motor Control

## Objective

Design and implement a timer-driven embedded control system using the AT89S52 microcontroller. Configure Timer 0 to provide precise timing for LED control, software PWM-based LED fading, and stepper motor speed control.

## Hardware Used

- AT89S52 Development Board
- LED
- Stepper Motor
- Speed Selection Buttons
- USB Programmer

## Software Used

- Keil µVision
- ProgISP

## Key Functions

| **Task** | **Function** |
| -------- | ------------ |
| 1        | Timer 0-based 1-second LED timing |
| 2        | Software PWM for gradual LED fading |
| 3        | Stepper motor speed control using Timer 0 interrupt |

## Features

- Register-level Timer 0 configuration
- Hardware timer-based timing without software delay loops for Tasks 1 and 2
- 1-second LED timing using Timer 0 overflow polling
- Software PWM for LED brightness control
- Gradual LED fading from 0% to 100% and back to 0%
- Timer interrupt-based stepper motor control
- Three stepper motor speed modes: Slow, Medium, and Fast
- Four-step stepper motor sequence control

## Files

- `task1.c` – Timer 0-based 1-second LED timing
- `task2.c` – Software PWM-based LED fading
- `task3.c` – Timer interrupt-based stepper motor speed control
