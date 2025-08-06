#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int val;
  struct node_t *right;
  struct node_t *left;
} node_t;

node_t *create_node(int val) {
  node_t *new_node = malloc(sizeof(node_t));
  if (!new_node) {
    return NULL;
  }
  new_node->val = val;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

node_t *insert_node(int val, node_t *root) {
  node_t *new_node = create_node(val);
  if (root == NULL) {
    return new_node;
  }
  if (val < root->val) {
    root->left = insert_node(val, root->left);
  } else if (val >= root->val) {
    root->right = insert_node(val, root->right);
  }
  return root;
}

void inordertraverse(node_t *root) {
  if (root == NULL) {
    return;
  }
  inordertraverse(root->left);
  printf("%d ", root->val);
  inordertraverse(root->right);
}

int main() {
  int n;
}
