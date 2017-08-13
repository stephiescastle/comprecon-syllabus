# Unit 1: Arduino and Git

[Slides](#)

## Materials
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

## Concepts
- Arduino / Microcontroller
- OOP
- Git/GitHub, Version control, repositories
- terminal

## Notes

### Arduino

- What is an arduino (microcontroller)
- Install it
	- Download and install
	- Can also use Web Editor
- In-class Tutorial: Simple circuits and programming (make diagrams with fritzing?)

	1. Turn on LED (order of operations and layout of arduino code)

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

	2. Make LED blink (illustrates loop) (maybe talk about order of operations and different loops here instead of in first exercise)
	3. Make a real LED blink (build excitement, it’s real stuff! Also easier to see)
	4. Make LED blink based on potentiometer value (sensor equivalent)  

	Okay, so it’s always looping and it’s always the same. What if we want it to do something different? Introduce conditionals:

	5. If potentiometer value is in a certain range
	6. Modes using switches

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

### Code Repositories / Sharing Code
