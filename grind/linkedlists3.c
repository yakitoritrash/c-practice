#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int val;
  struct node_t *next;
} node_t;

node_t *create_node(int val) {
  node_t *new_node = malloc(sizeof(node_t));

  return new_node;
}

