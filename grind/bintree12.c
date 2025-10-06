#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int val;
  struct node_t *left;
  struct node_t *right;
} node_t;

node_t* create_node(int val) {
  node_t *new_node = malloc(sizeof(node_t));
  if (!new_node) {
    printf("Memory allocation failed.\n");
    return NULL;
  }
  new_node->val = val;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

node_t *append(node_t *root, int val) {
  if (!root) {
    return create_node(val);
  }
  if (root->val < val) {
    root = append(root->right, val);
  } else if (root->val > val) {
    root = append(root->left, val);
  }
  return root;
}

void inorder(node_t *root) {

}


int main() {
  node_t *root = NULL;

}
