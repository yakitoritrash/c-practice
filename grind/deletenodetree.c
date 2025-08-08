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
  node_t *new_node = create_node(val);
  if (root == NULL) {
    return new_node;
  }
  if (val < root->val) {
    root->left = insert_node(val, root->left);
  } else if (val >= root->val) {
    root->right = insert_node(val, root->right);
  }
  return root;
}

void inordertraverse(node_t *root) {
  inordertraverse(root->left);
  printf("%d ", root->val);
  inordertraverse(root->right);
}

node_t *findmin(node_t *root) {
  root = root->left;
  while (root != NULL && root->right != NULL) {
    root = root->right;
  }
  return root;
}

node_t *delete_node(int del, node_t *root) {
  if (root == NULL) {
    return NULL;
  }
  if (root->val > del) {
    root->left = delete_node(del, root->left);
  } else if (root->val < del) {
    root->right = delete_node(del, root->right);
  } else {
    if (root->left == NULL) {
      node_t *tmp = root->right;
      free(root);
      return tmp;
    }
    if (root->right == NULL) {
      node_t *tmp = root->left;
      free(root);
      return tmp;
    }
    node_t *min = findmin(root); 
    root->val = min->val;
    root->left = delete_node(min->val, root->left);
  }
  return root;
}

int main() {
  int n;
  scanf("%d", 
}
