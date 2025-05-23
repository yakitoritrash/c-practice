#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int val;
  struct node_t *next;
} node_t;

node_t *create_node(int value) {
  node_t *new_node = malloc(sizeof(node_t));
  if (!new_node) {
    printf("Memory allocation failed");
    return NULL;
  }
  new_node->val = value;
  new_node->next = NULL;
  return new_node;
}

node_t *prepend(node_t *head, int value) {
  node_t *new_node = create_node(value);
  if (new_node == NULL) {
    return head;
  }
  new_node->next = head;
  head = new_node;
  return new_node;
}

node_t *reverse_list(node_t *head) {
  node_t *tmp = head;
  node_t *next = NULL;
  node_t *prev = NULL;
  while (tmp != NULL) {
    next = tmp->next;
    tmp->next = prev;
    prev = tmp;
    tmp = next;
  }
  return prev;
}
