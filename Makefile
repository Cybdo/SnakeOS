# Define the target ISO name
TARGET = myos.iso
ISO_DIR = isodir
GRUB_CFG = $(ISO_DIR)/boot/grub/grub.cfg

# Define compiler and linker flags
AS = as --32
CC = gcc -m32
LD = ld -m elf_i386
CFLAGS = -ffreestanding -nostdlib -nostartfiles -nodefaultlibs
LDFLAGS = -T boot/linker.ld  # Update this line to use the correct path

# Targets
all: $(TARGET)

# Step 1: Assemble boot.o
boot.o: boot/boot.s  # Change this line to point to the correct boot.s file location
	$(AS) -o $@ $<

# Step 2: Compile kernel.o
kernel.o: kernel/kernel.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Step 3: Link kernel.bin
kernel.bin: boot.o kernel.o
	$(LD) $(LDFLAGS) -o $@ boot.o kernel.o

# Step 4: Set up ISO directory structure
$(ISO_DIR)/boot/kernel.bin: kernel.bin
	mkdir -p $(ISO_DIR)/boot/grub
	cp kernel.bin $(ISO_DIR)/boot/kernel.bin

# Step 5: Create grub.cfg
$(GRUB_CFG):
	echo 'menuentry "myos" { multiboot /boot/kernel.bin }' > $(GRUB_CFG)

# Step 6: Build the ISO image
$(TARGET): $(ISO_DIR)/boot/kernel.bin $(GRUB_CFG)
	grub-mkrescue -o $(TARGET) $(ISO_DIR)

# Clean up build files
clean:
	rm -f *.o kernel.bin $(TARGET)
	rm -rf $(ISO_DIR)

