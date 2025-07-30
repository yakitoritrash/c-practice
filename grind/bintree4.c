#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void inordertraversal(node_t *root) {
  if (root == NULL) {
    return;
  }
  inordertraversal(root->left);
  printf("%d ", root->val);
  inordertraversal(root->right);
}

void postorder(node_t *root) {
  if (root == NULL) {
    return;
  }
  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->val);
}

void preorder(node_t *root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->val);
  preorder(root->left);
  preorder(root->right);
}

bool search(int val, node_t *root) {
  if (root == NULL) {
    return false;
  }
  if (val == root->val) {
    printf("true");
    return true;
  } else if (val > root->val) {
    search(val, root->right);
  } else {
    search(val, root->left);
  }
  printf("false");
  return false;
}
int main() {
  node_t *head = NULL;
  head = insert_node(40, head);
  head = insert_node(4, head);
  head = insert_node(45, head);
  head = insert_node(34, head);
  head = insert_node(55, head);
  head = insert_node(14, head);
  head = insert_node(48, head);
  head = insert_node(13, head);
  head = insert_node(15, head);
  head = insert_node(47, head);
  head = insert_node(49, head);
  printf("inorder: ");
  inordertraversal(head);
  printf("\n");
  printf("postorder: ");
  postorder(head);
  printf("\n");
  printf("preorder: ");
  preorder(head);
  printf("\n");
  search(5, head);
  search(4, head);
  search(50, head);
  search(48, head);
}

