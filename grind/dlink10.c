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

}
