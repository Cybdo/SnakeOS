//
// Created by cybdo on 23/06/2025.
//

#ifndef SNAKE_H
#define SNAKE_H
#include <stdint.h>
#include "print.h"
#include "port_io.h"
#include "random.h"

#define SNAKE_CHAR '@' // Character to represent the snake
#define SNAKE_COLOR 0xAA // Green color for the snake
void draw_snake(int x, int y);
void draw_border();
int snake_length;
void snake_tick();
#endif //SNAKE_H
