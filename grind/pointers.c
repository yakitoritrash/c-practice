#include <stdio.h>

// int *p, *q, *r;
void increment(int *p) {
  (*p)++;
}

int main() {
  int x = 42;
  int *p = &x; //save x's addr to p
  int **q = &p;
  increment(p);

  printf("%d ", x); //print out value of x
  return 0;
}
