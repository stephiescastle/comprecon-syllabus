# Lesson 2: Make built-in LED blink

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

# Lesson 3: Make external LED blink

![external led](http://stephiescastle.com/teaching/computation-reconsidered/external-led_bb.svg?v=4)

Purpose: Introduce concepts of basic electronics

- Breadboard
- Jumper cables
- 10kΩ resistor
- 3v LED
