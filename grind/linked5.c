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

  new_node -> data = value;
  new_node -> next = NULL;
  return new_node;
}

node_t *insert_at_head (node_t *head, int value) {
  node_t *new_node = create_node(value);
  if (new_node == NULL) {
    return head;
  }
  new_node -> next = head;
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
  return head;
}

node_t *insert_at_position(node_t *head, int value, int position) {
  node_t *new_node = create_node(value);
  if (position == 0) {
    return insert_at_head(head, value);
  }
  node_t *tmp = head;
  for (int i = 0; i < position; i++) {
    if (tmp == NULL) {
      return head;
    }
    tmp = tmp -> next;
  }
  new_node->next = tmp -> next;
  tmp -> next = new_node;
  
  return head;
}

node_t *delete_at_position(node_t *head, int position) {

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
      printf("Position out of bounds\n");
      return head;
    }
    tmp = tmp->next;
  }
  node_t *to_delete = tmp->next;
  if (to_delete == NULL) {
    printf("Nothing to delete at that position.\n");
    return head;
  }

  tmp->next = to_delete->next;
  free(to_delete);
  return head;
}

int main() {

  node_t *head = NULL;

  head = insert_at_head(head, 3);
  head = insert_at_head(head, 4);
  head = insert_at_head(head, 6);
  head = insert_at_end(head, 9);
  head = insert_at_position(head, 20, 1);
  head = delete_at_position(head, 2);

  node_t *tmp = head;
  while (tmp != NULL) {
    printf("%d -> ", tmp->data);
    tmp = tmp->next;
  }
  printf("NULL\n");

  printf("%d\n", sizeof(head));
  printf("%d", sizeof(node_t));
}
