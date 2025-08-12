#include <stdio.h>
#include <stdbool.h>
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
  } else if (val > root->val) {
    root->right = insert_node(val, root->right);
  }
  return root;
}

bool find(node_t *root, int needle) {
  if (root == NULL) {
    return false;
  }
  if (root->val == needle) {
    return true;
  }
  if (root->val < needle) {
    return find(root->right, needle);
  }
  return find(root->left, needle);
}


