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

node_t *delete_a_position(node_t *head, int position) {
  if (head == NULL) {
    return NULL;
  }

  if (position == 0) {
    node_t *to_be_deleted = head;
    head = head->next;
    free(to_be_deleted);
    return head;
  }

  node_t *tmp = head;
  for (int i = 0; i < position - 1; i++){
    if (tmp == NULL || tmp->next == NULL) {
      printf("out of bounds\n");
      return head;
    }
    tmp = tmp->next;
  }
  node_t *to_be_deleted = tmp->next;
  if (to_be_deleted == NULL) {
    printf("position out of bounds.\n");
    return head;
  }
  tmp->next = to_be_deleted->next;

  if (to_be_deleted->next != NULL) {
    to_be_deleted->next->prev = tmp;
  }

  free(to_be_deleted);
  return head;
}

node_t *delete_by_value(node_t *head, int value) {
  if (head == NULL) {
    return NULL;
  }
  if (head->data == value) {
    node_t *to_be_deleted = head;
    head = head->next;
    free(to_be_deleted);
    return head;
  }
  node_t *tmp = head;
  while (tmp->next != NULL && tmp->next->data != value) {
    tmp=tmp->next;
  }
  if (tmp->next == NULL) {
    printf("Nothing to delete here.\n");
  }
  node_t *to_be_deleted = tmp->next;
  tmp->next = to_be_deleted->next;
  if (to_be_deleted->next != NULL) {
    to_be_deleted->next->prev = tmp;
  }
  return head;
}

int main() {
  node_t *head = NULL;
  head = insert_at_head(head, 2);
  head = insert_at_head(head, 3);
  head = insert_at_head(head, 4);
  head = insert_at_end(head, 5);
  head = insert_at_position(head, 6, 1);

  head = delete_a_position(head, 2);
  head = delete_by_value(head, 5);
  node_t *tmp = head;
  while (tmp != NULL) {
    printf("%d <-> ", tmp->data);
    tmp = tmp->next;
  }

  printf("NULL\n");
}
