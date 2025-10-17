#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int val;
  struct node_t *left;
  struct node_t *right;
} node_t;

node_t* create_node(int val) {
  node_t *new_node = malloc(sizeof(node_t));
  if (!new_node) {
    printf("Memory allocation failed.\n");
    return NULL;
  }
  new_node->val = val;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

node_t* insert_node(int val, node_t *root) {
  if (root == NULL) {
    return create_node(val);
  }
  if (root->val <= val) {
    root->right = insert_node(val, root->right);
  } else {
    root->left = insert_node(val, root->left);
  }
  return root;
}

void inoder(node_t *root) {
  if (root == NULL) {
    return;
  }
  inoder(root->left);
  printf("%d ", root->val);
  inoder(root->right);
}

node_t *findmin(node_t *root) {
  while (root && root->left != NULL) {
    root = root->left;
  }
  return root;
}

node_t *deletenode(int x, node_t *root) {
  if (root == NULL) {
    return root;
  }
  if (x < root->val) {
    root->left = deletenode(x, root->left);
  } else if (x > root->val) {
    root->right = deletenode(x, root->right);
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
    root->right = deletenode(min->val, root->right);
  }
  return root;
}

node_t *inverse(node_t *root) {
  if (root == NULL) {
    return NULL;
  }
  
  return root;
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
  inoder(root);
  printf("\n");
  int x;
  scanf("%d", &x);
  root = deletenode(x, root);
  inoder(root);
}
