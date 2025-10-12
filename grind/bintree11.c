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
  if (root == NULL) {
    return create_node(val);
  }
  if (val <= root->val) {
    root->left = insert_node(val, root->left);
  } else {
    root->right = insert_node(val, root->right);
  }
  return root;
}

node_t *invert(node_t *root) {
  if (root == NULL) {
    return NULL;
  }
  node_t *tmp = root->left;
  root->left = root->right;
  root->right = tmp;
  invert(root->left);
  invert(root->right);
  return root;
}

node_t *findmin(node_t *root) {
  while (root && root->left != NULL) {
    root = root->left;
  }
  return root;
}

node_t *delete(node_t *root, int x) {
  if (root == NULL) {
    return root;
  }
  if (x < root->val) {
    root->left = delete(root->left, x);
  } else if (x > root->val) {
    root->right = delete(root->right, x);
  } else {
    if (root->left == NULL) {
      node_t *tmp = root->right;
      free(root);
      return tmp;
    } else if (root->right == NULL) {
      node_t *tmp = root->left;
      free(root);
      return tmp;
    } else if (root->right == NULL && root->left == NULL) {
      free(root);
      return NULL;
    }       
    node_t *min = findmin(root->right);
    root->val = min->val;
    root->right = delete(root->right, min->val);
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
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    root = insert_node(x, root);
    inorder(root);
    printf("\n");
  }
  printf("\n");
  int x;
  scanf("%d", &x);
  root = delete(root, x);
  inorder(root);
  printf("\n");
  invert(root);
  inorder(root);
}
