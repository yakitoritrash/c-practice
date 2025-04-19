#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
  int items[MAX_SIZE];
  int top;
} stack_t;
