#include <stdlib.h>
#include <stdio.h>

typedef struct node_t {
  int val;
  struct node_t *next;
} node_t;

node_t *create_node(int value) {
  node_t *new_node = malloc(sizeof(node_t));
  if (!new_node) {
    printf("Memory allocation failed.\n");
    return NULL;
  }
  new_node->val = value;
  new_node->next = NULL;
  return new_node;
}

node_t *prepend(node_t *head, int value) {
  node_t *new_node = create_node(value);
  if (new_node == NULL) {
    return head;
  }
  new_node->next = head;
  head = new_node;
  return new_node;
}

node_t *delete_middle(node_t *head) {
  int count = 0;
  node_t *tmp = head;
  while (tmp != NULL) {
    tmp = tmp->next;
    count++;
  }
  printf("%d", count);
  return head;
}

int main() {
  node_t *head = NULL;
  head = prepend(head, 5);
  head = prepend(head, 10);
  head = prepend(head, 15);
  head = prepend(head, 20);

  node_t *tmp = head;
  while (tmp != NULL) {
    printf("%d -> ", tmp->val);
    tmp = tmp->next;
  }
  printf("NULL\n");
  delete_middle(head);
}
