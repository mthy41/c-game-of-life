# Conway's game of live in C
[GIF demo](assets/demo.gif)
___
**This is a learning journey project, expect a lot of newbie C code!**
A very naive implementation of the Conway's game of live written in C. Made for a college presentation.
To compile and execute, run `make run` in the cloned directory. Modify world state in the `automatas.h` file by adding live cells.

### Play
By default the world update each 250000 miliseconds.

# Rules
___
1. Every dead cell with exacly three live neighboors become alive.
2. Every live cell with less than two neighboors dies from underporpulation.
3. Every live cell with more than tree live neighboors dies from overpopulation;
4. Every live cell with only two live neighboors stays alive.
