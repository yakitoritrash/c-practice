#include <stdio.h>

int main() {
  int arr[3];
  for (int i = 0; i < 3; i++) {
    scanf("%d", &arr[i]);
  }
  int max = arr[0];
  for (int i = 0; i < 3; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  printf("%d", max);
}
