#include "include/print.h"
#include "include/kernel.h"

// Video memory location
#define VIDEO_MEMORY 0xB8000

// Function to print a string to the screen
void print_string(const char *str) {
    volatile char *video_memory = (char *)VIDEO_MEMORY;
    while (*str) {
        *video_memory++ = *str++;   // Character
        *video_memory++ = 0x07;      // Attribute byte (light gray on black)
    }
}

