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
  new_node->val= val;
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
    insert_node(val, root->left);
  } else if (val >= root->val) {
    insert_node(val, root->right);
  }
  return root;
}

void inordertraversal(node_t *root) {
  if (root == NULL) {
    return;
  }
  inordertraversal(root->left);
  printf("%d -> ", root->val);
  inordertraversal(root->right);
}

int main() {
  node_t *head = NULL;
//  int n;
//  scanf("%d", &n);
//  for (int i = 0; i <= n; i++) {
//    int x;
//    scanf("%d", &x);
//    head = insert_node(x, head); 
//    inordertraversal(head);
//    printf("\n");
//  }
  head = insert_node(5, head);
  head = insert_node(68, head);
  head = insert_node(95, head);
  head = insert_node(3, head);
  head = insert_node(56, head);
  inordertraversal(head);
}
