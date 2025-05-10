#include <stdio.h>

int sum(int arr[], int n) {
  if (n <= 0) {
    return 0;
  } else {
    return sum(arr, n - 1) + arr[n-1];
  }
}

int main() {
  int arr[] = {5, 6, 7, 4, 3, 7};
  int n = 4;
  int result = sum(arr, n);
  printf("%d", result);
}
