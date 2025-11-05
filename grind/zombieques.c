#include <stdio.h>

int main() {
  int x, y;
  scanf("%d %d", &x, &y);
  int arr[y];
  for (int i = 0; i < y; i++) {
    scanf("%d", &arr[i]);
  }
  int count = 0;
  for (int i = 0; i < y; i++) {
    count += (arr[i] % 2) + arr[i] / 2;
  }
  if (x - count > 0) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
}
