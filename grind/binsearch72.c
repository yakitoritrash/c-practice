#include <stdio.h>

int binsearch(int arr[], int size, int n) {
  int lo = 0;
  int hi = size - 1;
  while (lo < hi) {
    int m = lo + (hi - lo) / 2;
    int v = arr[m];
    if (v == n) {
      return m;
    } else if (v > n) {
      hi = m;
    } else {
      lo = m + 1;
    }
  }
  return -1;
}

int main() {
  int arr[] = {4, 5, 6, 7, 8, 9};
  int size = sizeof(arr) / sizeof(arr[0]);
  int n = 5;
  int res = binsearch(arr, size, n);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("%d", res);
}
