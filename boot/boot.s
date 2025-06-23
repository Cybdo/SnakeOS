# Multiboot header
.section .multiboot
    .align 4
    .long 0x1BADB002          # magic
    .long 0x00000003          # flags: request memory info and video mode
    .long -(0x1BADB002 + 0x00000003) # checksum
    .long 0                   # header_addr (optional)
    .long 0                   # load_addr (optional)
    .long 0                   # load_end_addr (optional)
    .long 0                   # bss_end_addr (optional)
    .long 0                   # entry_addr (optional)
    .long 0                   # mode_type (0 = linear framebuffer)
    .long 1024                # width
    .long 768                 # height
    .long 32                  # depth (bits per pixel)

# Entry point
.section .text
.global _start
_start:
    mov $kernel_main, %eax         # Load address of kernel_main
    call *%eax                     # Call kernel_main

halt:
    hlt                            # Halt the CPU
    jmp halt                       # Infinite loop

