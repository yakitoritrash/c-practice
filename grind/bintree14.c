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
    printf("Memory allocation failed.\n");
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
  if (root->val < val) {
    root->right = insert_node(val, root->right);
  } else {
    root->left = insert_node(val, root->left);
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

node_t *inverse(node_t *root) {
  if (root == NULL) {
    return NULL;
  }
  node_t *tmp = root->left;
  root->left = root->right;
  root->right = tmp;
  inverse(root->left);
  inverse(root->right);
  return root;
}

node_t *findmin(node_t *root) {
  while (root && root->left != NULL) {
    root = root->left;
  }
  return root;
}

node_t *delete_node(int x, node_t *root) {
  if (root == NULL) {
    return root;
  }
  
  if (root->val < x) {
    root->right = delete_node(x, root->right);
  } else if (root->val > x) {
    root->left = delete_node(x, root->left);
  } else {

  }
  
  return root;
}


int main() {
  node_t *root = NULL;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    root = insert_node(x, root);
  }
  inorder(root);
  inverse(root);
  printf("\n");
  inorder(root);
}
