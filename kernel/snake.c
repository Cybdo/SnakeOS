//
// Created by cybdo on 23/06/2025.
// ASCII Snake
//
#include "snake.h"


int snake_length = 0;



void draw_border() {
    for (int x = 0; x < VGA_WIDTH; x++) {
        // Draw top border
        vga_buffer[VGA_WIDTH+ x] = (uint16_t)(SNAKE_CHAR | 0xFF << 8); // White color
        // Draw bottom border
        vga_buffer[(VGA_HEIGHT - 1) * VGA_WIDTH + x] = (uint16_t)(SNAKE_CHAR | 0xFF << 8); // White color
    }
    for (int y = 1; y < VGA_HEIGHT; y++) {
        // Draw left border
        vga_buffer[y * VGA_WIDTH] = (SNAKE_CHAR | 0xFF << 8); // White color
        // Draw right border
        vga_buffer[y * VGA_WIDTH + (VGA_WIDTH - 1)] = (SNAKE_CHAR | 0xFF << 8); // White color
    }
}

void draw_snake(int x, int y) {
    // Draw the snake at position (x, y)
    vga_buffer[y * VGA_WIDTH + x] = (uint16_t)(SNAKE_CHAR | (SNAKE_COLOR << 8)); // Green color
}

void snake_tick(unsigned int seed) {
    draw_snake(randint(1, VGA_WIDTH - 2, seed), randint(2, VGA_HEIGHT - 2, seed));
    snake_length++;
    print_string("Score: ",0);
    char score_str[8];
    itoa_simple(snake_length, score_str); // Convert int to string (base 10)
    print_string(score_str,7);
}
