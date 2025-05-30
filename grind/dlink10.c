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
    printf("Memory allocation failed.\n");
    return NULL;
  }
  new_node->val = val;
  new_node->next = NULL;
  new_node->prev = NULL;
  return new_node;
}

node_t *prepend(node_t *head, int val) {
  node_t *new_node = create_node(val); 
  if (new_node == NULL) {
    return head;
  }
  new_node->next = head;
  if (new_node->next != NULL) {
    new_node->next->prev = new_node->next;
  }
  head = new_node;
  return new_node;
}

node_t *append(node_t *head, int val) {
  node_t *new_node = create_node(val);
  if (head == NULL) {
    return new_node;
  }
  if (new_node == NULL) {
    return head;
  }
  node_t *tmp = head;
  while(tmp->next != NULL) {
    tmp = tmp->next;
  }
  tmp->next = new_node;
  if (tmp != NULL) {
    new_node->prev = tmp;
  }
  return head;
}

node_t *insert_at(node_t *head, int val, int pos) {
  node_t *new_node = create_node(val);
  if (head == NULL) {
    return NULL;
  }
  if (pos == 0) {
    return prepend(head, val);
  }
  node_t *tmp = head;
  for (int i = 0; i < pos; i++) {
    if (tmp == NULL) {
      printf("Out of bounds.\n");
      return head;
    }
    tmp = tmp->next;
  }
  new_node->next = tmp->next;
  tmp->next = new_node;
  if (new_node->next != NULL) {
    new_node->next->prev = new_node->next;
  }
  new_node->prev = tmp;
  return head;
}

node_t *delete_by_val(node_t *head, int val) {
  if (head == NULL) {
    return NULL;
  }
  if (val == head->val) {
    node_t *to_remove = head;
    head = head->next;
    free(to_remove);
    return head;
  }
  node_t *tmp = head;
  while (tmp->next != NULL && tmp->next->val != val) {
    tmp = tmp->next;
  }
  if (tmp->next == NULL) {
    printf("Nothing to delete here.\n");
    return head;
  }
  node_t *to_remove = tmp->next;
  tmp->next = to_remove->next;
  if (to_remove->next != NULL) {
    to_remove->next->prev = tmp;
  }
  free(to_remove);
  return head;
}

node_t *delete_at(node_t *head, int pos) {
  if (head == NULL) {
    return NULL;
  }
  if (pos == 0) {
    node_t *to_remove = head;
    head = head->next;
    free(to_remove);
    return head;
  }
  node_t *tmp = head;
  for (int i = 0; i < pos - 1; i++) {
    tmp = tmp->next;
  }
  if (tmp->next == NULL) {
    printf("Nothing to delete.\n");
    return head;
  }
  node_t *to_remove = tmp->next;
  tmp->next = to_remove->next;
  if (to_remove->next != NULL) {
    to_remove->next->prev = tmp;
  }
  free(to_remove);
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
//  head = delete_by_val(head, 2);
  node_t *tmp = head;
  while (tmp != NULL) {
    printf("%d <-> ", tmp->val);
    tmp = tmp->next;
  }
  printf("NULL\n");
}
