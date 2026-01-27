include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int val;
  struct node_t *left;
  struct node_t *right;
  int height;
} node_t;

int height(node_t *root) {
  if (root == NULL) {
    return 0;
  }
  return root->height;
}

int get_balance(node_t *root) {
  if (root == NULL) {
    return 0;
  }
  return height(root->left) - height(root->right);
}
