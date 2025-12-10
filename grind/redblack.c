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

node_t *get_uncle(node_t *n) {
  if (n->parent == NULL || n->parent->parent == NULL) {
    return NULL;
  }
  if (n->parent == n->parent->parent->left) {
    return n->parent->parent->right;
  } else {
    return n->parent->parent->left;
  }
}

void insert_fixup(node_t **root, node_t *z) {
  while (z->parent != NULL && z->parent->color == RED) {
    node_t *uncle = get_uncle(z);
    node_t *grandparent = z->parent->parent;
    if (uncle != NULL && uncle->color == RED) {
      z->parent->color = BLACK;
      uncle->color = BLACK;
      grandparent->color = RED;
      z = grandparent;
    } else {
      if (z->parent == grandparent->left) {
        if (z == z->parent->right) {
          z = z->parent;
          left_rotate(root, z);
        }
        z->parent->color = BLACK;
        grandparent->color = RED;
        right_rotate(root, grandparent);
      } else {
        if (z == z->parent->left) {
          z = z->parent;
          right_rotate(root, z);
        }
        z->parent->color = BLACK;
        grandparent->color = RED;
        left_rotate(root, grandparent);
      }
    }
  }
  (*root)->color = BLACK;
}

void insert(node_t **root, int val) {
  node_t *x = *root;
  node_t *y = NULL;
  while (x != NULL) {
    y = x;
    if (val < x->val) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  node_t *z = create_node(val);
  z->parent = y;
  if (y == NULL) {
    *root = z;
  } else if (val < y->val) {
    y->left = z;
  } else {
    y->right = z;
  }
  insert_fixup(root, z);
}


