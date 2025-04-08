#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int data;
  struct node_t *next;
} node_t;

node_t *create_node(int value) {
  node_t *new_node = malloc(sizeof(node_t));
  if (!new_node) {
    printf("Memory allocation failed.\n");
    return NULL;
  }

  new_node -> data = value;
  new_node -> next = NULL;

  return new_node;
}

node_t *insert_at_head(node_t *head, int value) {
  node_t *new_node = create_node(value);
  if (new_node == NULL) {
    return head;
  }

  new_node->next = head;
  return new_node;
}

node_t *insert_at_end(node_t *head, int value) {
  node_t *new_node = create_node(value);


  
}

int main() {
  node_t *head = NULL;
  head = insert_at_head(head, 5);
  head = insert_at_head(head, 10);
  head = insert_at_head(head, 15);

  node_t *tmp = head;
  while (tmp != NULL) {
    printf("%d -> ", tmp -> data);
    tmp = tmp->next;
  }

  printf("NULL\n");

  return 0;
}
