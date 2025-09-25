#include <stdio.h>

int binsearch(int arr[], int size, int needle) {
  int hi = size - 1;
  int lo = 0;
  while (lo < hi) {
    int m = lo + (hi - lo) / 2;
    int v = arr[m];
    if (v == needle) {
      return m;
    } else if (v > needle) {
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
  int needle = 4;
  int res = binsearch(arr, size, needle);
  printf("%d", res);
}

