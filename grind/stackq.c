#include <stdlib.h>
#include <stdio.h>

typedef struct node_t {
  int val;
  struct node_t *prev;
} node_t;

node_t *create_node(int val) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  if (!new_node) {
    return NULL;
  }
  new_node->val = val;
  new_node->prev = NULL;
  return new_node;
}

node_t *push(int val, node_t *head) {
  node_t *new_node = create_node(val);
  if (head == NULL) {
    return new_node;
  }
  new_node->prev = head;
  head = new_node;
  return head;
}

node_t *pop(node_t *head) {
  if (head == NULL) {
    return NULL;
  }
  node_t *to_delete = head;
  head = head->prev;
  free(to_delete);
  return head;
}

void printlist(node_t *head) {
  node_t *tmp = head;
  while (tmp != NULL) {
    printf("%d ", tmp->val);
    tmp = tmp->prev;
  }
}

int main() {
  int n;
  node_t *head = NULL;
  while (1) {
    if (scanf("%d", &n) != 1) {
      printf("Invalid.\n");
      break;
    }
    if (n == 1) {
      int x;
      scanf("%d", &x);
      head = push(x, head);
    } else if (n == 2) {
      head = pop(head);
    } else if (n == 3) {
      printlist(head);
    } else if (n == 4) {
      printf("Exiting");
      break;
    } else {
      printf("Invalid");
    }
  }
  return 0;
}
