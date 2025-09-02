#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int val;
  struct node_t *left;
  struct node_t *right;
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
  if (root == NULL) {
    return create_node(val);
  }
  if (val <= root->val) {
    root->left = insert_node(val, root->left);
  } else {
    root->right = insert_node(val, root->right);
  }
  return root;
}

node_t *invert(node_t *root) {
  if (root == NULL) {
    return NULL;
  }
  node_t *tmp = root->left;
  root->left = root->right;
  root->right = tmp;
  invert(root->left);
  invert(root->right);
  return root;
}
