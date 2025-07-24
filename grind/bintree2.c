#include <stdio.h>
#include <stdlib.h>

typedef struct root_t {
  int val;
  struct root_t *left;
  struct root_t *right;
} root_t;

root_t *create_node(int value) {
  root_t *new_root = malloc(sizeof(root_t));

  return new_root;
}
