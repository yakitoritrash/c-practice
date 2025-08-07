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

node_t *prepend(int val, node_t *head) {
  node_t *new_node = create_node(val);
  if (head == NULL) {
    return new_node;
  }
  new_node->next = head;
  return head;
}

node_t *append(int val, node_t *head) {
  node_t *new_node = create_node(val);
  node_t *tmp = head;
  while (tmp != NULL) {
    tmp = tmp->next;
  }
  tmp->next = new_node;
  return head;
}

void printlist(node_t *head) {
  node_t *tmp = head;
  while (tmp != NULL) {
    printf("%d ", tmp->val);
    tmp = tmp->next;
  }
}

int main() {
  node_t *head = NULL;
  head = prepend(5, head);
  head = prepend(6, head);
  head = prepend(7, head);
  head = append(8, head);
  head = append(9, head);
  printlist(head);
}
