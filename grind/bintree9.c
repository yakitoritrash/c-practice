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

node_t *findmin(node_t *root) {
  while (root && root->left != NULL) {
    root = root->left;
  }
  return root;
}

node_t *delete_node(node_t *root, int x) {
  if (root == NULL) {
    return root;
  }
  if (x < root->val) {
    root->left = delete_node(root->left, x);
  } else if (x > root->val) {
    root->right = delete_node(root->right, x);
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
    root->right = delete_node(root->right, min->val);
  }
  return root;
}

void inordertraverse(node_t *head) {

}
