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
    return NULL;Write code to define a doubly linked list node (struct
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
  new_node->prev = NULL;

  if (head != NULL) {
    head->prev = new_node;
  }
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
  


}
