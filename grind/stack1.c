#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
  int items[MAX_SIZE];
  int top;
} stack_t;

stack_t *init_stack() {
  stack_t *new_stack = malloc(sizeof(stack_t));
  if (new_stack == NULL) {
    return NULL;
  }
  new_stack->top = -1;
  return new_stack;
}

int is_empty(stack_t *stack) {
  if (stack->top == -1) {
    return 1;
  }
  return 0;
}

int is_full(stack_t *stack
