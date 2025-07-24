#include <stdio.h>
#include <stdlib.h>

typedef struct leaf_t {
  int val;
  struct leaf_t *left;
  struct leaf_t *right;
} leaf_t;
