//
// Created by cybdo on 23/06/2025.
//

#ifndef RANDOM_H
#define RANDOM_H

#include <stdint.h>
#define RANDOM_SEED 0x12345678 // Default seed value

typedef struct{
    uint64_t size;        // Size of input in bytes
    uint32_t buffer[4];   // Current accumulation of hash
    uint8_t input[64];    // Input to be used in the next step
    uint8_t digest[16];   // Result of algorithm
}MD5Context;

int randint(int min, int max, int seed);


#endif //RANDOM_H
