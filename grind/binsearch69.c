#include <stdio.h>

int binsearch(int arr[], int size, int n) {
  int lo = 0;
  int hi = size - 1;
  while (lo <= hi) {
    int m = lo + (hi - lo) / 2;
    int v = arr[m];
    if (v == n) {
      return m;
    } else if (v < n) {
      lo = m + 1;
    } else {
      hi = m;
    }
  }
  return -1;
}

int main() {
  int arr[] = {3, 4, 5, 6, 7, 8, 9};
  int size = sizeof(arr) / sizeof(arr[0]);
  int n= 3;
  int res = binsearch(arr, size, n);
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  printf("%d", res);
}
