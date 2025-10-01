#include <stdio.h>

int Collatz(int n) {
  if (n == 1) {
    return 0;
  } else {
    if (n % 2 == 0) {
      return 1 + Collatz(n / 2);
    } else {
      return 1 + Collatz((3 * n) + 1);
    }
  }
}

int main() {
  int x;
  scanf("%d", &x);
  int res = Collatz(x);
  printf("%d", res);
}
