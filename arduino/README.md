# Unit 1: Arduino and Git

Slides: [Link](https://docs.google.com/presentation/d/1WJ0OYdD2WST4ZEv52NQbj38ncqVNBmu7CWIfpUAHbgM/edit?usp=sharing)  

**Unit Materials**
- Laptop
- Arduino Uno or Mega
- USB cable (A to B)
- Breadboard
- Jumper cables
- 1 LED
- 1 potentiometer
- 4 resistors
- 1 switch
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

## Lesson 1: Turn on built-in LED ([link](https://github.com/stephiescastle/computation-reconsidered/tree/master/arduino/Lessons/Lesson-1))

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

---

# Concepts

## Computers and Object-Oriented Programming

We just discovered basically everything a computer/program can do:

- Basic math
- Simple decisions
- Move data from one place to another
- Loop

It’s the combinations of these things **arranged into a set of instructions** that make a computer program.

### Development Strategies

The lessons above walked us through an iterative exploratory exercise. "Exploratory programming" is a super fun, creative and effective way to learn how to program, but what about when you have a specific goal in mind?

#### Basic Development Method
- Define the problem that needs to be solved
- Design a solution
- Write a program that implements the solution
- Compile and run that program
- Test and debug

#### Complex Development Method

To tackle a complex problem:

- **break the problem down into a series of one-step problems**
- apply the basic development method (including testing and debugging) to each individual problem
- combine all of your solutions into a master program. Note that this step will also require testing and debugging 

## Version Control and GitHub

- terminal
- sharing code
- version control
- github

--- 

# Helpful Links / More Resources

* [When to use pinMode](https://www.baldengineer.com/when-to-use-arduinos-pinmode-and-why.html)


