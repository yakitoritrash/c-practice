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
  if (!new_node) {
    return head;
  }
  if (head == NULL) {
    return new_node;
  }
  new_node->next = head;
  head->prev = new_node;
  return new_node;
}

void middle_node(node_t *head, int n) {
  if (head == NULL) return;
  node_t *tmp = head;
  for (int i = 0; i < n / 2; i++) {
    if (tmp->next == NULL) break;
    tmp = tmp->next;
  }
  if (n % 2 == 0) {
    if (tmp->next != NULL) {
      printf("%d %d", tmp->val, tmp->next->val);
    }
  } else {
    printf("%d", tmp->val);
  }
}

void print_list(node_t *head, int n) {
  node_t *tmp = head;
  for (int i = 0; i < n && tmp != NULL; i++) {
    printf("%d ", tmp->val);
    tmp = tmp->next;
  }
  printf("\n");
}

void free_list(node_t *head) {
  node_t *tmp;
  while (head != NULL) {
    tmp = head;
    head = head->next;
    free(tmp);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  node_t *head = NULL;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d ", &x);
    head = insert_head(x, head);
  }
  middle_node(head, n);
  printf("\n");
  print_list(head, n);
  free_list(head);
  return 0;
}
