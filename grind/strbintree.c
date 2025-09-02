#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct node_t {
  char *val;
  struct node_t *left;
  struct node_t *right;
} node_t;

node_t *create_node(char *val) {
}
