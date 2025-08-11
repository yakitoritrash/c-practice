#include <stdio.h>
#include <stdbool.h>
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
  if (val < root->val) {
    root->left = insert_node(val, root->left);
  } else if (val > root->val) {
    root->right = insert_node(val, root->right);
  }
  return root;
}

bool find(int val, node_t *root) {
  if (root == NULL) {
    return false;
  }
  if (root->val == val) {
    return true;
  }
  if (val < root->val) {
    return find(val, root->left);
  }
  return find(val, root->right);
}

node_t *findmin(node_t *root) {
  while (root && root->left != NULL) {
    root = root->left;
  }
  return root;
}

node_t *delete_node(int needle, node_t *root) {
  if (root == NULL) {
    return root;
  }
  if (needle < root->val) {
    root->left = delete_node(needle, root->left);
  } else if (needle > root->val) {
    root->right = delete_node(needle, root->right);
  } else {
    if (root->left == NULL) {
      node_t *tmp = root->right;
      free(root);
      return tmp;
    } else if (root->right == NULL) {
      node_t *tmp = root->left;
      free(root);
      return tmp;
    } else if (root->left == NULL && root->right == NULL) {
      free(root);
      return NULL;
    }
    node_t *min = findmin(root->right);
    root->val = min->val;
    root->right = delete_node(min->val, root->right);
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
  int n;
  scanf("%d", &n);
  node_t *root = NULL;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    root = insert_node(x, root);
  }
  int x;
  scanf("%d", &x);
  int y;
  scanf("%d", &y);
  inorder(root);
  delete_node(x, root);
  printf("\n");
  inorder(root);
  printf("\n");
  int res = find(y, root);
  printf("%d", res);
}
