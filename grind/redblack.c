#include <stdio.h>
#include <stdlib.h>

typedef enum{
  RED,
  BLACK
} Color;

typedef struct node_t {
  int val;
  struct node_t *left;
  struct node_t *right;
  struct node_t *parent;
  Color color;
} node_t;

//the root is always BLACK
//RED nodes cannot have RED children
//every path from a node to its NULL descendants must have the same number of BLACK nodes

node_t *create_node(int val) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->val = val;
  new_node->left = NULL;
  new_node->right = NULL;
  new_node->parent = NULL;
  new_node->color = RED;
  return new_node;
}

void left_rotate(node_t **root, node_t *to_rotate) {
  node_t* y = to_rotate->right;
  to_rotate->right = y->left;
  if (y->left != NULL) {
    y->left->parent = to_rotate;
  }
  y->parent = to_rotate->parent;
  if (to_rotate->parent == NULL) {
    *root = y;
  }
  else if (to_rotate->parent->left == to_rotate) {
    to_rotate->parent->left = y;
  }
  else if (to_rotate->parent->right == to_rotate) {
    to_rotate->parent->right = y;
  }
  y->left = to_rotate;
  to_rotate->parent = y;
}

void right_rotate(node_t **root, node_t *to_rotate) {
  node_t* y = to_rotate->left;
  to_rotate->left = y->right;
  if (y->right != NULL) {
    y->right->parent = to_rotate;
  }
  y->parent = to_rotate->parent;
  if (to_rotate->parent == NULL) {
    *root = y;
  }
  else if (to_rotate->parent->left == to_rotate) {
    to_rotate->parent->left = y;
  }
  else if (to_rotate->parent->right == to_rotate) {
    to_rotate->parent->right = y;
  }
  y->right = to_rotate;
  to_rotate->parent = y;
}

void insert(node_t **root, int val) {
  node_t *x = *root;

}
