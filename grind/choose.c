#include <stdio.h>

unsigned long long factorial(int num) {
  if (num == 0 || num == 1) {
    return 1;
  }
  unsigned long long result = 1;
  for (int i = 2; i <= num; i++) {
    result *= i;
  }
  return result;
}

unsigned long long combinations(int n, int r) {
  if (r > n) {
    return 0;
  }
  unsigned long long numerator = factorial(n);
  unsigned long long denominator = factorial(r) * factorial(n - r);
  return (numerator / denominator);
}


int main() {
  int N, M, P, E;
  scanf("%d %d %d %d", &N, &M, &P, &E);
  unsigned long long pen = combinations(N, P);
  unsigned long long era = combinations(M, E);
  unsigned long long x = pen * era;
  printf("%llu", x);
}
