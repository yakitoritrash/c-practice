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
  if (root == NULL) {
    return create_node(val);
  }
  if (root->val <= val) {
    root->left = insert_node(val, root->left);
  } else {
    root->right = insert_node(val, root->right);
  }
  return root;
}

void inoder(node_t *root) {

}
