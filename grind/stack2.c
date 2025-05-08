#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node_t {
  int val;
  struct node_t *prev;
} node_t;

node_t *create_node(int value) {
  node_t *new_node = malloc(sizeof(node_t));
  if (!new_node) {
    printf("Memory allocation failed.\n");
    return NULL;
  }
  new_node->val = value;
  new_node->prev = NULL;
  return new_node;
}

node_t *push(node_t *top, int value) {
  node_t *new_node = create_node(value);
  if (new_node == NULL) {
    return top;
  }
  if (top == NULL) {
    return new_node;
  }
  new_node->prev = top;
  top = new_node;
  return new_node;
}

node_t *pop(node_t *top) {
  if (top == NULL) {
    printf("Nothing to delete.\n");
    return NULL;
  }
  node_t *to_pop = top;
  top = top->prev;
  free(to_pop);
  return top;
}

node_t *peek(node_t *top) {
  if (top == NULL) {
    printf("Stack is empty.\n");
    return NULL;
  }
  printf("%d",top->val);
  printf("\n");
  return top;
}

void print_stack(node_t *top) {
  printf("Stack top to bot: ");
  while (top != NULL) {
    printf("%d ", top->val);
    top = top->prev;
  }
  printf("\n");
}

bool isEmpty(node_t *top) {
  if (top == NULL) {
    return true;
    printf("true");
  } else {
    return false;
    printf("false");
  }
}

int main() {
  node_t *stack = NULL;
  stack = push(stack, 30);
  stack = push(stack, 20);
  stack = push(stack, 10);
  stack = push(stack, 40);

  print_stack(stack);
  peek(stack);
  stack = pop(stack);

  print_stack(stack);
  isEmpty(stack);
}
