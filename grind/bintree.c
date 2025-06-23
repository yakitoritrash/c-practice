#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node_t {
  int val;
  struct node_t *left;
  struct node_t *right;
} node_t;

node_t *create_node(int value) {
  node_t *new_node = malloc(sizeof(node_t));
  if (!new_node) {
    printf("Memory allocation failed.\n");
    return NULL;
  }
  new_node->val = value;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

node_t *insert_node(node_t *root, int value) {
  if (root == NULL) {
    return create_node(value);
  }
  if (value < root->val) {
    root->left = insert_node(root->left, value);
  } else if (value > root->val) {
    root->right = insert_node(root->right, value);
  }
  return root;
}

void inorder_traversal(node_t *root) {
  if (root == NULL) {
    return;
  }
  inorder_traversal(root->left);
  printf("%d ", root->val);
  inorder_traversal(root->right);
}

bool search_node(node_t *root, int target) {
  if (root == NULL) {
    return false;
  }
  if (root->val == target) {
    return true;
  }
  if (target > root -> val) {
    return search_node(root->right, target);
  } else {
    return search_node(root->left, target);
  }
}

node_t *find_min(node_t *root) {
  while (root && root->left != NULL) {
    root = root->left;
  }
  return root;
}

node_t *delete_a_node(node_t *root, int value) {
  if (root == NULL) {
    return NULL;
  }

  if (root->val > value) {
    root->left = delete_a_node(root->left, value);
  } else if (value > root->val) {
    root->right = delete_a_node(root->right, value);
  } else {
    if (root->left == NULL && root->right == NULL) {
      free(root);
      return NULL;
    } else if (root->left == NULL) {
      node_t *tmp = root->right;
      free(root);
      return tmp;
    } else if (root->right == NULL) {
      node_t *tmp = root->left;
      free(root);
      return tmp;
    } else {
      node_t *successor = find_min(root->right);
      root->val = successor->val;
      root->right = delete_a_node(root->right, successor->val);
    }
  }
  return root;
}

