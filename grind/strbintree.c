#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct node_t {
  char *val;
  struct node_t *left;
  struct node_t *right;
} node_t;

node_t *create_node(char *val) {
  node_t *new_node = malloc(sizeof(node_t));
  if (!new_node) {
    return NULL;
  }
  new_node->val = malloc(strlen(val) + 1);
  if (!new_node->val) {
    free(new_node);
    return NULL;
  }
  strcpy(new_node->val, val);
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

node_t *insert_node(char *val, node_t *root) {
  if (root == NULL) {
    return create_node(val);
  }
  if (strcmp(val, root->val) <= 0) {
    root->left = insert_node(val, root->left);
  } else {
    root->right = insert_node(val, root->right);
  }
  return root;
}
