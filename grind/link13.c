#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int data;
  struct node_t *next;
  struct node_t *prev;
} node_t;

 node_t *create_node(int value) {
  node_t *new_node = malloc(sizeof(node_t));
  if (!new_node) {
    printf("Memory allocation failed.\n");
    return NULL;
  }

  new_node->data = value;
  new_node->next = NULL;
  new_node->prev = NULL;
  return new_node;
}

node_t *insert_at_head(node_t *head, int value) {
  node_t *new_node = create_node(value);
  if (new_node == NULL) {
    return head;
  }
  new_node->next = head;
  if (head != NULL) {
    head->prev = new_node;
  }
  head = new_node;
  return new_node;
}

node_t *insert_at_end(node_t *head, int value) {
  node_t *new_node = create_node(value);
  if (new_node == NULL) {
    return head;
  }

  if (head == NULL) {
    return new_node;
  }
  
  node_t *tmp = head;
  while (tmp->next != NULL) {
    tmp = tmp->next;
  }
  tmp->next = new_node;
  new_node->prev = tmp;
  return head;
}

node_t *insert_at_position(node_t *head, int value, int position) {
  node_t *new_node = create_node(value);
  if (head == NULL) {
    return new_node;
  }
  if (position == 0) {
    return insert_at_head(head, value);
  }
  node_t *tmp = head;
  for (int i = 0; i < position - 1; i++) {
    if (tmp == NULL || tmp->next == NULL) {
      printf("Out of bounds\n");
    }
    tmp = tmp->next;
  }
  new_node->next = tmp->next;

  new_node->prev = tmp;
  tmp->next = new_node;
  if (tmp->next != NULL) {
    tmp->next->prev = new_node;
  }
  return head;
}


