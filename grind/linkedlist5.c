#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int val;
  struct node_t *next;
  struct node_t *prev;
} node_t;

node_t *create_node(int val) {
  node_t *new_node = malloc(sizeof(node_t));
  if (!new_node) {
    return NULL;
  }
  new_node->val = val;
  new_node->next = NULL;
  new_node->prev = NULL;
  return new_node;
}

node_t *prepend(int val, node_t *head) {
  node_t *new_node = create_node(val);
  if (head == NULL) {
    return new_node;
  }
  new_node->next = head;
  head->prev = new_node;
  head = new_node;
  return head;
}

node_t *append(int val, node_t *head) {
  node_t *new_node = create_node(val);
  if (head == NULL) {
    return new_node;
  }
  node_t *tmp = head;
  while (tmp->next != NULL) {
    tmp = tmp->next;
  }
  tmp->next->next = new_node;
  if (tmp->next->next != NULL) {
    new_node->prev = tmp->next->next;
  }
  return head;
}

node_t *delete_node(int val, node_t *head) {
  if (val == head->val) {
    node_t *to_delete = head;

  }
}


