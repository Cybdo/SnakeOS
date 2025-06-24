#include <stdint.h>
#include "print.h"


// Function to print a string to VGA text mode
void print_string(const char* str, int position) {
    int i = 0;
    while (str[i] != '\0') {
        vga_buffer[position + i] = (uint16_t)str[i] | (0x0F << 8); // Character + color attribute
        i++;
    }
}
//function to clear screen
void clear_screen(uint8_t color) {
    for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
        vga_buffer[i] = ' ' | (color << 8); // Clear with space character and specified color
    }
}

void clean_print(const char* str) {
    clear_screen(0);
    print_string(str,0);
}