#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int val;
  struct node_t *next;
  struct node_t *prev;
} node_t;

node_t *create_node(int val) {
  noe_t *new_node = malloc(sizeof(node_t));
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
  free(tmp);
}

node_t *prepend(int val, node_t *head) {
  node_t *new_node = create_node(val);
  if (head == NULL) {
    head = new_node;
    return new_node;
  }
  new_node->next = head;
  head->prev = new_node;
  head = new_node;
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

node_t *delete_node_by_val(int val, node_t *head) {
  if (head == NULL) {
    return NULL;
  }
  if (head->val == val) {
    node_t *to_delete = head;
    head = to_delete->next;
    free(to_delete);
    return head;
  }
  node_t *tmp = head;
  while (tmp->next != NULL && tmp->next->val != val) {
    tmp = tmp->next;
  }
  if (tmp == NULL || tmp->next == NULL) {
    printf("No value found.\n");
    return head;
  }
  node_t *to_delete = tmp->next;
  tmp->next = to_delete->next;
  if (tmp) {
    to_delete->next->prev = tmp;
  }
  return head;
}

int main() {
  node_t *head = NULL;
  head = append(5, head);
  head = append(1, head);
  head = prepend(2, head);
  printlist(head);
  printf("\n");
  head = delete_node_by_val(9, head);
  printlist(head);
}
