#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int val;
  struct node_t *next;
  struct node_t *prev;
} node_t;

node_t *create_node(int value) {
  node_t *new_node = malloc(sizeof(node_t));
  if (!new_node) {
    return NULL;
  }
  new_node->val = value;
  new_node->next = NULL;
  new_node->prev= NULL;
  return new_node;
}

node_t *insert_head(int value, node_t *head) {
  node_t *new_node = create_node(value);
  if (head == NULL) {
    return new_node;
  }
  new_node->next = head;
  head->prev = new_node;
  new_node = head;
  return head;
}

void middle_node(node_t *head, int n) {
  node_t *tmp = head;
  for (int i = 0; i <= n / 2; i++) {
    tmp = tmp->next;
  }
  if (n % 2 == 0) {
    printf("%d %d", tmp->val, tmp->next->val);
  } else if (n % 2 != 0) {
    printf("%d", tmp->val);
  }
}

void print_list(node_t *head) {
}
k
