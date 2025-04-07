#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int data;
  struct node_t *next;
} node_t;

node_t *create_new_node(int value) {
  node_t *new_node = malloc(sizeof(node_t));
  if (!new_node) {
    printf("Memory allocation failed.");
    return NULL;
  }

  new_node -> data = value;
  new_node -> next = NULL;

  return new_node;
}

node_t *insert_at_head(node_t *head, int value) {

}
