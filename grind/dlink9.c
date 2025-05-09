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
    if (tmp== NULL || tmp->next == NULL) {
      printf("Out of bounds");
      return head;
    }
    tmp = tmp->next;
  }
  new_node->next = tmp->next;
  tmp->next = new_node;
  return head;
}

node_t *delete_at(node_t *head, int position) {
  if (head == NULL) {
    return NULL;
  }
  if (position == 0) {
    node_t *to_delete = head;
    head = to_delete->next;
    free(to_delete);
    return head;
  }
  node_t *tmp = head;
  for (int i = 0; i <= position; i++) {
    if (tmp == NULL || tmp->next == NULL) {
      printf("out of bounds.\n");
      return head;
    }
    tmp = tmp->next;
  }
  node_t *to_delete = tmp->next;
  tmp->next = to_delete->next;
  free(to_delete);
  return head;
}

node_t *delete_by_value(node_t *head, int value) {
  if (head == NULL) {
    return NULL;
  }
  if (head->val == value) {
    node_t *to_delete = head;
    head = to_delete->next;
    free(to_delete);
    return head;
  }
  node_t *tmp = head;
  while (tmp->next->val != value && tmp->next != NULL) {
    tmp = tmp->next;
  }
  if (tmp->next == NULL) {
    printf("nothing to delete.\n");
    return head;
  }
  node_t *to_delete = tmp->next;
  tmp->next = to_delete->next;
  free(to_delete);
  return head;
}

int main() {
  node_t *head = NULL;
  head = prepend(head, 3);
  head = prepend(head, 5);
  head = append(head, 7);
  
  node_t *tmp = head;
  while (tmp == NULL) {
    printf("%d ", tmp->val);
    tmp = tmp->next;
  }
  printf("NULL\n");
}
