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

node_t *prepend(node_t *head, int value) {
  node_t *new_node = create_node(value);
  if (new_node == NULL) {
    return head;
  }

  new_node->next = head;
  if (head->next != NULL) {
    head->prev = new_node;
  }

  head = new_node;
  return new_node;
}

node_t *append(node_t *head, int value) {
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
  tmp->next = new_node->next;
  new_node->prev = tmp;
  return head;
}

node_t *insert_at(node_t *head, int value, int position) {
  node_t *new_node = create_node(value);
  if (new_node == NULL) {
    return head;
  }
  if (head == NULL) {
    return NULL;
  }

  if (position == 0) {
    return prepend(head, value);
  }

  node_t *tmp = head;
  for (int i = 0; i < position; i++) {
    if (tmp == NULL || tmp->next == NULL) {
      printf("Out of bounds");
      return head;
    }
    tmp = tmp->next;
  }

}
