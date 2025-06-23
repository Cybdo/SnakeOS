//
// Created by cybdo on 23/06/2025.
// ASCII Snake
//
#include "snake.h"
#include "print.h"

void draw_snake(int x, int y) {
    // Draw the snake at position (x, y)
    // For simplicity, we will just print a character at the specified position
    // In a real graphics environment, you would use pixel manipulation
    // Here we just print the snake character at the current position
    vga_buffer[y * VGA_WIDTH + x] = (uint16_t)(SNAKE_CHAR | (SNAKE_COLOR << 8)); // Green color
}
