#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int val;
  struct node_t *next;
} node_t;

node_t *create_node(int value) {
  node_t *new_node = malloc(sizeof(node_t));
  if (!new_node) {
    printf("Memory allocation failed.\n");
    return NULL;
  }
  new_node->val = value;
  new_node->next = NULL;
  return new_node;
}

node_t *prepend(node_t *head, int value) {
  node_t *new_node = create_node(value);
  if (new_node== NULL) {
    return head;
  }
  if (head== NULL) {
    return new_node;
  }
  new_node->next = head;
  head = new_node;
  return new_node;
}

node_t *append(node_t *head, int value) {
  node_t *new_node = create_node(value);
  if (head == NULL) {
    return new_node;
  }
  if (new_node == NULL) {
    return head;
  }
  node_t *tmp = head;
  while (tmp != NULL) {
    tmp = tmp->next;
  }
  tmp->next = new_node;
  return head;
}



