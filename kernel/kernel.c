#include <stdint.h>
#include "keyboard.h"
#include "idt.h"
#include "print.c"
#include "random.c"
#include "snake.c"

unsigned int ms_clock = 0;



/*// Main kernel function
void kernel_main() {

    load_idt();
    init_keyboard(); // Initialize keyboard handling
    //const char* message = "Hello World! My name is Cybdo";
    //print_string(message);
    set_video_mode(); // Set video mode to 320x200x256
    //clear_screen(0); // Clear the screen with black color



    while (1); // Infinite loop to keep the kernel running
}
*/

typedef struct {
    uint32_t flags;
    uint32_t mem_lower;
    uint32_t mem_upper;
    // ... other fields ...
    uint32_t framebuffer_addr_low;
    uint32_t framebuffer_addr_high;
    uint32_t framebuffer_pitch;
    uint32_t framebuffer_width;
    uint32_t framebuffer_height;
    uint8_t  framebuffer_bpp;
    // ... more fields ...
} multiboot_info_t;
/*
void draw_pixel(uint32_t x, uint32_t y, uint32_t color, multiboot_info_t* mb_info) {
    uint32_t* fb = (uint32_t*)((uint64_t)mb_info->framebuffer_addr_low | ((uint64_t)mb_info->framebuffer_addr_high << 32));
    uint32_t pitch = mb_info->framebuffer_pitch / 4; // 4 bytes per pixel (32bpp)
    fb[y * pitch + x] = color;
}

void fill_screen(uint32_t color, multiboot_info_t* mb_info) {
    uint32_t* fb = (uint32_t*)((uint64_t)mb_info->framebuffer_addr_low | ((uint64_t)mb_info->framebuffer_addr_high << 32));
    uint32_t width = mb_info->framebuffer_width;
    uint32_t height = mb_info->framebuffer_height;
    uint32_t pitch = mb_info->framebuffer_pitch / 4;
    for (uint32_t y = 0; y < height; y++) {
        for (uint32_t x = 0; x < width; x++) {
            fb[y * pitch + x] = color;
        }
    }
}
*/

void delay_ms(int milliseconds) {
    for (int i = 0; i < milliseconds; i++)
    {
        for (volatile int j = 0; j < 270000; j++);
            // shitty delay loop which will be influenced by the CPU speed
            // maybe replace at some point with a better delay function
            // accurate-ish for my machine
    }
}


void kernel_main(multiboot_info_t* mb_info) {
    //if (mb_info->framebuffer_addr_low && mb_info->framebuffer_width && mb_info->framebuffer_height) {
    //    fill_screen(0x000000FF, mb_info);
    //}
    //else
    //{
        // Fallback to text mode if framebuffer is not available
        print_string("Framebuffer not available, running in text mode.",0);
        delay_ms(1000);
        clean_print("Test sleep");
        clear_screen(0);
        print_string("                                                 SNAKE GAME BY CYBDO! ",0);
        //draw_snake(VGA_WIDTH,VGA_HEIGHT);
        //draw_snake(0,VGA_HEIGHT);
        //draw_snake(VGA_WIDTH,0);
        draw_border();

    //}
    while (1) {
        if (ms_clock % (500- snake_length)  == 0 && 500- snake_length >= 250) snake_tick(ms_clock);
        else if (500- snake_length <= 250) {clear_screen(0); print_string("You Win!",0); while (1);}
        delay_ms(1);
        ms_clock++;
    }

}