#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int value;
  struct node_t *next;
} node_t;

node_t *create_node(int value) {
  node_t *new_node = malloc(sizeof(node_t));
  if (!new_node) {

  }
}
