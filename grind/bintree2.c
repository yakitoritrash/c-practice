#include <stdio.h>
#include <stdlib.h>

typedef struct root_t {
  int val;
  struct root_t *left;
  struct root_t *right;
} root_t;

root_t *create_node(int value) {
  root_t *new_root = malloc(sizeof(root_t));
  if (!new_root) {
    printf("Memory allocation failed.\n");
    return NULL;
  }
  new_root->val = value;
  new_root->left = NULL;
  new_root->right = NULL;
  return new_root;
}

root_t *
