#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int val;
  struct node_t *next;
} node_t;

node_t *create_node(int val) {
  node_t *new_node = malloc(sizeof(node_t));
  if (!new_node) {
    return NULL;
  }
  new_node->val = val;
  new_node->next = NULL;
  return new_node;
}

node_t *insert_node(int val, node_t *head) {
  node_t *new_node = create_node(val);
  if (head == NULL) {
    return new_node;
  }
  new_node->next = head;
  head = new_node;
  return head;
}

node_t *dequeue(node_t *head) {
  node_t *tmp = head;
  while (tmp != NULL) {
    tmp = tmp->next;
  }
  node_t *to_delete = tmp;
  printf("Node deleting is: %d", tmp->val);
  free(to_delete);
  return head;
}

void printlist(node_t *head) {
  node_t *tmp = head;
  while (tmp != NULL) {
    printf("%d ", tmp->val);
    tmp = tmp->next;
  }
}
