# Retro Engine 


This project is a software rendered 2D game engine that is written completely from Scratch in C99. It has NO SDl, no OPENGL, no OS headers in the core and the engine also draws into the plain pixel array, and a sma per platform wrapper that puts the array onto the screen

## My Goals 

- I want zero external dependencies in the engine core 
- Making sure i utilize zero dynamic allocation and that all the memory lives in one static arena 
- Int math ONLY, meaning no floats
- **CAN BE USED BY ANYTHING WITH A C COMPILER**

## What I have so far 

- `engine_api.h` - the only interface between teh core and the platform
- `engine_core.c` - this would be the engine itself

It is still very early on, right now I just have the core compiling and filling a 320x240 buffer with just one solid color and there is no window yet.

## How to build it 

`gcc -x c -std=c99 -Wall -Wextra -c engine_core.c -o engine_core.o`

make sure to force the compiler to compile in C just in case it wants to do it in c++ or other languages
