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
  } else if (val > root->val) {
    root->right = insert_node(val, root->right);
  }
  return root;
}

node_t *find_min(node_t *root) {
  while (root && root->left != NULL) {
    root = root->left;
  }
  return root;
}

node_t *delete_node(node_t *root, int x) {
  if (root == NULL) {
    return root;
  }
  if (root->val < x) {
    root->right = delete_node(root->right, x);
  } else if (root->val > x) {
    root->left = delete_node(root->left, x);
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
    node_t *min = find_min(root->right);
    root->val = min->val;
    root->right = delete_node(root->right, min->val);
  }
  return root;
}

node_t *invert_tree(node_t *root) {
  if (root == NULL) {
    return NULL;
  }
  node_t *tmp = root->right;
  root->right = root->left;
  root->left = tmp;
  invert_tree(root->left);
  invert_tree(root->right);
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
int main() {
  node_t *root = NULL;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    root = insert_node(x, root);
  }
  inordertraverse(root);
  invert_tree(root);
  printf("\n");
  inordertraverse(root);
  printf("\n");
  int y;
  scanf("%d", &y);
  root = delete_node(root, y);
  printf("\n");
  inordertraverse(root);
  invert_tree(root);
  printf("\n");
  inordertraverse(root);
}
