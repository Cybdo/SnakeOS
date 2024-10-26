#include <stdint.h>

// VGA text mode buffer starts at this memory location
volatile uint16_t* vga_buffer = (uint16_t*)0xB8000;
const int VGA_WIDTH = 80;
const int VGA_HEIGHT = 25;

// Function to print a string to VGA text mode
void print_string(const char* str) {
    int i = 0;
    while (str[i] != '\0') {
        vga_buffer[i] = (uint16_t)str[i] | (0x0F << 8); // Character + color attribute
        i++;
    }
}

// Main kernel function
void kernel_main() {
    const char* message = "Hello World! My name is Omar";
    print_string(message);
    while (1); // Infinite loop to keep the kernel running
}

