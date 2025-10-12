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
  if (root == NULL) {
    return create_node(val);
  }
  if (root->val < val) {
    root->right = append(root->right, val);
  } else if (root->val >= val) {
    root->left = append(root->left, val);
  }
  return root;
}

void inorder(node_t *root) {
  if (root == NULL) {
    return;
  }
  inorder(root->left);
  printf("%d ", root->val);
  inorder(root->right);
}

int main() {
  node_t *root = NULL;
  root = append(root, 10);
  root = append(root, 20);
  root = append(root, 30);
  root = append(root, 40);
  inorder(root);
}
