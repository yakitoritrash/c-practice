#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int val;
  struct node_t *next;
} node_t;

node_t *create_node(int val) {
  node_t *new_node = malloc(sizeof(node_t));
  if (!new_node) {
    printf("Memory allocation failed.\n");
    return NULL;
  }
  new_node->val = val;
  new_node->next = NULL;
  return new_node;
}

node_t *append(int val, node_t *head) {
  node_t *new_node = create_node(val);
  if (head == NULL) {
    head = new_node;
    return head;
  }
  node_t *tmp = head;
  while (tmp->next != NULL) {
    tmp = tmp->next;
  }
  tmp->next = new_node;
  return head;
}

node_t *prepend(int val, node_t *head) {
  return head;
}

int main() {}
