#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct root_t {
  int val;
  struct root_t *left;
  struct root_t *right;
} root_t;

root_t *create_node(int value) {
  root_t *new_root = malloc(sizeof(root_t));
  if (!new_root) {
    printf("Memory allocation failed.\n");
    return NULL;
  }
  new_root->val = value;
  new_root->left = NULL;
  new_root->right = NULL;
  return new_root;
}

root_t *insert_node(int value, root_t *root) {
  if (root == NULL) {
    return NULL;
  }
  root_t *new_root = malloc(sizeof(root_t));
  if (value < root->val) {
    root->left = insert_node(value, root);
  } else if (value > root->val) {
    root->right = insert_node(value, root);
  }
  return root;
}

void inordertaversal(root_t *root) {
  if (root == NULL) {
    return;
  }
  inordertaversal(root->left);
  printf("%d ", root->val);
  inordertaversal(root->right);
}

void searchtree(root_t *root) {
  
}
