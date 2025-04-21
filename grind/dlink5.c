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
  if (head != NULL) {
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
  tmp->next = new_node;
  new_node->prev = tmp;
  return head;
}

node_t *insert_at(node_t *head, int value, int position) {
  node_t *new_node = create_node(value);
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
  tmp->next = new_node;
  new_node->next = tmp->next;
  new_node->prev = tmp;
  if (new_node->next != NULL) {
    new_node->next->prev = new_node;
  }
  return head;
}

node_t *delete_at(node_t *head, int position) {
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
    if (tmp == NULL || tmp->next == NULL) {
      printf("nothing to delete here.\n");
      return head;
    }
    tmp = tmp->next;
  }
  node_t *to_delete = tmp->next;
  tmp->next = to_delete->next;
  if (to_delete->next != NULL) {
    to_delete->next->prev = tmp;
  }
  free(to_delete);
  return head;
}

node_t *delete_value(node_t *head, int value) {
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
  while (tmp->next != NULL && tmp->next->data == value) {
    tmp = tmp->next;
  }
  if (tmp->next == NULL) {
    printf("Nothing to delete here.\n");
    return head;
  }
  node_t *to_delete = tmp->next;
  tmp->next = to_delete->next;
  if (to_delete->next != NULL) {
    to_delete->next->prev = tmp;
  }
  free(to_delete);
  return head;
}


int main() {
  node_t *head = NULL;
  head = prepend(head, 1);
  head = prepend(head, 2);
  head = append(head, 3);
  head = insert_at(head, 4, 1);
  head = prepend(head, 5);
  head = delete_at(head, 2);
  head = delete_value(head, 2);
  node_t *tmp = head;
  while (tmp != NULL) {
    printf("%d <-> ", tmp->data);
    tmp = tmp->next;
  }
  printf("NULL\n");
}
