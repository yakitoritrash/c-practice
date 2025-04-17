#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int data;
  struct node_t *next;
} node_t;

node_t *create_node(int value) {
  node_t *new_node = malloc(sizeof(node_t));
  if (!new_node) {
    printf("Memory allocation failed.\n");
    return NULL;
  }
  new_node->data = value;
  new_node->next = NULL;
  return new_node;
}

node_t *append(node_t *head, int value) {
  node_t *new_node = create_node(value);
  if (new_node == NULL) {
    return head;
  }
  new_node->next = head;
  return new_node;
}

node_t *prepend(node_t *head, int value) {
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
  return head;
}

node_t *insert_at(node_t *head, int value, int position) {
  node_t *new_node = create_node(value);
  if (head == NULL) {
    return NULL;
  }

  if (position == 0) {
    return append(head, value);
  }
  node_t *tmp = head;
  for (int i = 0; i < position - 1; i++) {
    if (tmp = NULL) {
      return NULL;
    }
    tmp = tmp->next;
  }
  new_node->next = tmp->next;
  tmp->next = new_node;
  return head;
}

node_t *delete_position(node_t *head, int position) {
  if (head == NULL) {
    return NULL;
  }
  if (position == 0) {
    node_t *to_delete = head;
    head = head->next;
    free(to_delete);
    return head;
  }

  node_t *tmp = head;
  for (int i = 0; i < position - 1; i++) {
    if (tmp = NULL || tmp->next == NULL) {
      printf("Out of bounds\n");
    } 
     tmp = tmp->next;
  }
  node_t *to_delete = tmp->next;
  to_delete->next = tmp->next;
  free(to_delete);
  return head;
}

node_t *delete_by_value(node_t *head, int value) {
  if (head == NULL) {
    return NULL;
  }
  if (head->data == value) {
    node_t *to_delete = head;
    head = head->next;
    free(to_delete);
    return head;
  }

  node_t *tmp = head;

  while (tmp->next != NULL && tmp->next->data != value) {
    tmp = tmp->next;
  }


}

