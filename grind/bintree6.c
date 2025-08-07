#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int val;
  struct node_t *right;
  struct node_t *left;
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
  if (root == NULL) {
    return;
  }
  inordertraverse(root->left);
  printf("%d ", root->val);
  inordertraverse(root->right);
}

void preorder(node_t *root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->val);
  preorder(root->left);
  preorder(root->right);
}

void postorder(node_t *root) {
  if (root == NULL) {
    return;
  }
  preorder(root->left);
  preorder(root->right);
  printf("%d ", root->val);
}

int main() {
  int n;
  scanf("%d", &n);
  node_t *root  = NULL;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    root = insert_node(x, root);
    inordertraverse(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
  }
}
