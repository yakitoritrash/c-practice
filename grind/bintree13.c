#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int val;
  struct node_t *left;
  struct node_t *right;
} node_t;

node_t* create_node(int val) {
  node_t *new_node = NULL;
  if (!new_node) {
    printf("Memory allocation failed");
    return NULL;
  }
  new_node->val = val;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

node_t* insert_node(int val, node_t *root) {

  return root;
}
