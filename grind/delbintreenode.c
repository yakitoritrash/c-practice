#include <stdbool.h>
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
  if (val < root->val) {
    root->left = insert_node(val, root->left);
  } else if (val > root->val) {
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

bool find(int needle, node_t *root) {
  if (root == NULL) {
    return false;
  }
  if (root->val == needle) {
    return true;
  }
  if (needle < root->val) {
    find(needle, root->left);
  }
  find(needle, root->right);
  return false;
}

node_t *findmin(node_t *root) {
  while (root && root->left != NULL) {
    root = root->left;
  }
  return root;
}

node_t *delete_node(node_t *root, int del) {

}
