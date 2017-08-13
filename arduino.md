# Unit 1: Arduino and Git

Slides: link goes here

**Unit Materials**
- Laptop
- Arduino Uno or Mega
- USB cable (A to B)
- Breadboard
- Jumper cables
- 1 LED
- 1 potentiometer
- 1 resistor
- 2 switches
- 1 button

**Concepts**
- Arduino / Microcontroller
- OOP
- Git/GitHub, Version control, repositories
- terminal

# Arduino
https://www.arduino.cc/

- What is an arduino (microcontroller)
- Download and install: https://www.arduino.cc/en/Main/Software

## Turn on built-in LED

Purpose: The Arduino "Hello World"

- Laptop
- Arduino
- USB Cable

## Make built-in LED blink

Purpose: Learn about order of operations and program setup in Arduino. Emphasize how it's a giant loop.

- Variables (outside of setup for scope reasons. Okay so why not in loop? Because it will reset it every time.
- Setup (all the code that happens once at the start)
- Loop
- Variables (ref: https://www.arduino.cc/en/Reference/VariableDeclaration )
	- Variable Scope
	- Declare and Initialize variables
	- Order of operations (elaborate on this more, not just variables, the whole patch is order of operations)
		- declare (int x)
		- Initialize when assigning a value (x = 1)
		- Can do all in one step: int x = 1

## Make external LED blink

Purpose: Introduce concepts of basic electronics

- Breadboard
- Jumper cables
- 120 ohm resistor
- 3v LED

## Use a knob to control the blink rate

Purpose: Introduce a manipulatable variable. The equivalent of a "sensor"

- Potentiometer
- 120 ohm resistor

`Okay, so it’s always looping and it’s always the same. What if we want it to do something different?`

## Using Conditionals

### If knob is in a value range

Purpose: Introduce using number ranges as a conditional

### Modes using switches/toggle

Purpose: Introduce mode switching

- switch
- 120 ohm resistor

### Momentary modes (momentary button)

Purpose: Introduce use of momentary buttons

- button
- 120 ohm resistor

-----------

`draft`
We just discovered basically everything a computer/program can do. These basic things a computer can do. It’s the combinations of these things that make programs happen (and also the fact that a computer can do hundreds of these things at a time)
Basic math
Simple decisions
Move data from one place to another
Loop
We just did an iterative exploratory exercise. Super fun and creative way and is also an effective way to learn. But what if you have an idea of something specific you want to create? 
Development Concepts
Define the problem that needs to be solved
Design a solution
Knowing what a computer can do and the components of what a programming language can do
Write a program that implements the solution
Compile and run that program
Test and debug

## Code Repositories / Sharing Code
