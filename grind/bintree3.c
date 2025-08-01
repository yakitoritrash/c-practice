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
    printf("Memory allocation failed.\n");
    return NULL;
  }
  new_node->val = val;
  new_node->right = NULL;
  new_node->left = NULL;
  return new_node;
}

node_t *insert_node(int val, node_t *root) {
  node_t *new_node = create_node(val);
  if (root == NULL) {
    return new_node;
  }
  if (val < root->val) {
    root->left = insert_node(val, root->left);
  } else if (new_node->val >= root->val) {
    root->right = insert_node(val, root->right);
  }
  return root;
}

bool search_node(int val, node_t *root) {
  if (root == NULL) {
    return false;
  }
  if (val == root->val) {
    return true;
  } else if (val < root->val) {
    return search_node(val, root->left);
  } else if (val > root->val) {
    return search_node(val, root->right);
  }
  return false;
}

void inordertraversal(node_t *root) {
  if (root == NULL) {
    return;
  }
  inordertraversal(root->left);
  printf("%d ",root->val);
  inordertraversal(root->right);
  return;
}

void preordertraversal(node_t *root) {
  if (root == NULL) {
    return; 
  }
  preordertraversal(root->left);
  preordertraversal(root->right);
  printf("%d ", root->val); 
}

int main() {
  node_t *head = NULL;
  head = insert_node(5, head);
  head = insert_node(6, head);
  head = insert_node(7, head);
  head = insert_node(3, head);
  head = insert_node(4, head);
  head = insert_node(10, head);
  inordertraversal(head);
  printf("\n");
  bool res = search_node(6, head);
  printf("%d\n", res);
  preordertraversal(head);
}
