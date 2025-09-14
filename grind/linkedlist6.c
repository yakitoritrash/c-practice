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
    return NULL;
  }
  new_node->val = val;
  new_node->next = NULL;
  new_node->prev = NULL;
  return new_node;
}

node_t *append(int val, node_t *head) {
  node_t *new_node = create_node(val);
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

void printlist(node_t *head) {
  node_t *tmp = head;
  while (tmp != NULL) {
    printf("%d <-> ", tmp->val);
    tmp = tmp->next;
  }
  printf("NULL");
}
int main() {
  node_t *head = NULL;
  head = append(5, head);
  head = append(1, head);
  printlist(head);
}

