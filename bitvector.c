#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct bitv8 {
  uint32_t val;
  uint8_t *vector;
} bitv8;

bitv8 *create_bitv8(uint32_t val) {
  bitv8 *bv8 = (bitv8 *)malloc(sizeof(bitv8));
  if (bv8) {
    bv8->val = val;
    uint8_t bytes = val / 8 + 1;
    bv8->vector = (uint8_t *)calloc(bytes, sizeof(uint8_t));
    return bv8;
  } else {
    return NULL;
  }
}

void del_bitv8(bitv8 **bv8) {
  if (bv8 && (*bv8)->vector) {
    free((*bv8)->vector);
  }
  if (bv8) {
    free(*bv8);
  }
  *bv8 = NULL;
}

bool set_bitv8(bitv8 *bv8, uint8_t bit) {
  return bv8->vector[bit / 8] |= (0x1 << (bit % 8)) ? true : false;
}

bool clear_bitv8(bitv8 *bv8, uint8_t bit) {
  return bv8->vector[bit / 8] &= ~(0x1 << (bit % 8)) ? true : false;
}

bool get_bitv8(bitv8 *bv8, uint8_t bit) {
  if (bit <= bv8->val && bv8 && bv8->vector) {
    return (bv8->vector[bit / 8] >> bit % 8) & 0x1;
  }
  return false;
}
