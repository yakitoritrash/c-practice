#include <stdio.h>

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);

    int a[n];
    int o = 0, e = 0;

    for (int i = 0; i < n; i++) {
      scanf("d", &a[i]);
      if (a[i] % 2 == 1) {
        o++;
      } else {
        e++;
      }
    }

    if ((e % 2 == 1) && (o % 2 == 1)) {
      printf("0\n");
    } else {
      printf("1\n");
    }
  }
  return 0;
}
