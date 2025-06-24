#ifndef PRINT_H
#define PRINT_H

void print_string(const char *str, int position);
void clear_screen(uint8_t color);
void clean_print(const char *str);

const int VGA_WIDTH = 80;
const int VGA_HEIGHT = 25;
volatile uint16_t* vga_buffer = (uint16_t*)0xB8000;
// VGA text mode buffer starts at this memory location


#endif // PRINT_H

