# LED Inversion Game

A fun and interactive 3x3 LED game built with Arduino Nano, where each of the 9 LEDs on the display acts as a button. The game’s objective is simple yet challenging: invert the LEDs in such a way that all of them are turned on simultaneously!

## How It Works:

The game features a 3x3 grid of LEDs, each of which can be toggled between ON and OFF states. When a button is pressed (corresponding to a specific LED), it inverts its own state and also inverts the state of nearby LEDs based on its position. The challenge is to strategically press the buttons to turn all the LEDs ON.

## Button Layout

The buttons are numbered as follows:

| 0 | 1 | 2 |
|---|---|---|

| 3 | 4 | 5 |
|---|---|---|

| 6 | 7 | 8 |
|---|---|---|


## Button Behavior

When a button is pressed, the corresponding LEDs are toggled as follows:

- **Button 0**: Inverts LEDs 0, 1, 3
- **Button 1**: Inverts LEDs 0, 1, 2
- **Button 2**: Inverts LEDs 1, 2, 4, 5
- **Button 3**: Inverts LEDs 0, 3, 6
- **Button 4**: Inverts LEDs 1, 3, 4, 5, 7
- **Button 5**: Inverts LEDs 2, 5, 8
- **Button 6**: Inverts LEDs 3, 4, 6, 7
- **Button 7**: Inverts LEDs 6, 7, 8
- **Button 8**: Inverts LEDs 4, 5, 7, 8

## In Other Words

- **Corner Buttons (0, 2, 6, 8)** invert themselves plus all the adjacent buttons.
- **Middle-Side Buttons (1, 3, 5, 7)** invert themselves plus the adjacent corner buttons.
- **Center Button (4)** inverts itself, plus the adjacent middle-side buttons.

## Game Objective

The goal is to press the buttons in such a way that all 9 LEDs are ON at the same time. When this happens, the game plays a victory sound, and the player can start a new random game.

## Features

- Interactive 3x3 grid of LEDs
- Real-time state inversion of LEDs based on button presses
- Buzzer feedback for button presses and winning states
- Random starting patterns for replayability
- Power-saving mode with an inactivity buzzer
- Victory sequence with alternating LED flashes and a sound signal

## Hardware Requirement

- Arduino Nano
- Breadboard/Wires or custom PCB based on the circuit diagram provided in the project files
- 9 x Button LEDs arranged in a 3x3 grid for input
- 9 x 1K Ohm Resistors
- Battery (9V)
- Connector for a 9V Battery
- 2 Sets of 15-Pin Header Pins (Male and Female)
- Toggle Switch
- Buzzer (Optional)

## Installation and Setup

1. Clone this repository to your local machine:
   ```bash
   git clone https://github.com/DelPineAI/Light_Box_Project.git
   
2. Connect the hardware as per the wiring diagram provided in the project files.

3. Upload the code to your Arduino Nano using the Arduino IDE.

4. In the Arduino IDE, install the 'Keypad' Library by Mark Stanley and Alexander Brevig.

5. Power up the Arduino, and the game will start with a random pattern of LEDs.

## Author

**Edward Del Pino**  
*May 2024*

- [LinkedIn](https://www.linkedin.com/in/edward-del-pino)
- [GitHub](https://github.com/DelPineAI)
- [Instagram](https://www.instagram.com/edwarddelpiiino/)
 
