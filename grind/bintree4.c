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
  printf("inorder: %d ", root->val);
  inordertraversal(root->right);
}

void postorder(node_t *root) {
  if (root == NULL) {
    return;
  }
  postorder(root->left);
  postorder(root->right);
  printf("postorder: %d ", root->val);
}

void preorder(node_t *root) {
  if (root == NULL) {
    return;
  }
  printf("preorder: %d ", root->val);
  preorder(root->left);
  preorder(root->right);
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
  inordertraversal(head);
  printf("\n");
  postorder(head);
  printf("\n");
  preorder(head);
  printf("\n");
}

