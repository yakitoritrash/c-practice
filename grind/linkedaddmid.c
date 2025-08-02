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

node_t *insert_at_head(int val, node_t *head) {
  node_t *new_node = create_node(val);
  if (head == NULL) {
    return new_node;
  }
  new_node->next = head;
  head->prev = new_node;
  head = new_node;
  return head;
}

node_t *insert_middle(int val, node_t *head, int size) {
  node_t *new_node = create_node(val);
  node_t *tmp = head;
  for (int i = 0;i < size / 2 - 1; i++) {
    tmp = tmp->next;
  }
  node_t *next_old = tmp->next;
  tmp->next = new_node;
  new_node->prev = tmp;
  new_node->next = next_old;
  next_old->prev = new_node;
  return head;
}

void printlist(node_t *head) {
  node_t *tmp = head;
  while (tmp!= NULL) {
    printf("%d ", tmp->val);
    tmp = tmp->next;
  }
}

int main() {
  node_t *head = NULL;
  head = insert_at_head(5, head);
  head = insert_at_head(6, head);
  head = insert_at_head(7, head);
  head = insert_at_head(8, head);
  head = insert_at_head(9, head);
  head = insert_at_head(10, head);
  head = insert_middle(11, head, 6);
  printlist(head);
}
