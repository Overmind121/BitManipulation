#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef struct bitv8 bitv8;

bitv8 *create_bitv8(uint32_t val);

void del_bitv8(bitv8 **bv8);

bool set_bitv8(bitv8 *bv8, uint8_t *bit);

bool clear_bitv8(bitv8 *bv8, uint8_t *bit);

bool get_bitv8(bitv8 *bv8, uint8_t *bit);
