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
- We're using the [Arduino Uno](http://www.arduino.org/products/boards/arduino-uno). Some students will be using the [Arduino Mega](http://www.arduino.org/products/boards/arduino-mega-2560)
	> Check for processer type
- Download and install: https://www.arduino.cc/en/Main/Software

## Lesson 1: Turn on built-in LED

Purpose: The "Hello World" for Arduino

- Laptop
- Arduino
- USB Cable

## Lesson 2: Make built-in LED blink

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

## Lesson 3: Make external LED blink

![external led](http://stephiescastle.com/teaching/computation-reconsidered/external-led_bb.svg?v=4)

Purpose: Introduce concepts of basic electronics

- Breadboard
- Jumper cables
- 10kΩ resistor
- 3v LED

## Lesson 4: Use a knob to control the blink rate

![external led with potentiometer](http://stephiescastle.com/teaching/computation-reconsidered/external-led-pot_bb.svg?v=4)

Purpose: Introduce a manipulatable variable. The equivalent of a "sensor"

- Potentiometer
- 10kΩ resistor

`Okay, so it’s always looping and it’s always the same. What if we want it to do something different?`

> Work in `for` and `while` loops. Right now this only covers `if/else` statements

## Lesson 5: Using conditionals: If knob is in a value range

Purpose: Introduce using number ranges as a conditional

## Lesson 6: Using conditionals: Switch between modes

![external led with potentiometer and switch](http://stephiescastle.com/teaching/computation-reconsidered/external-led-pot-toggle_bb.svg?v=4)

Purpose: Introduce mode switching

- switch
- 10kΩ resistor

## Lesson 7: Using conditionals: Momentary modes (momentary button)

![external led with potentiometer, switch and button](http://stephiescastle.com/teaching/computation-reconsidered/external-led-pot-toggle-button_bb.svg?v=4)

Purpose: Introduce use of momentary buttons

- button
- 10kΩ resistor

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
