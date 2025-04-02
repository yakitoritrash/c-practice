#include <stdio.h>

int binsearch(int arr[], int n,  int size) {
  int hi = size - 1;
  int lo = 0;

  for (int i = 0; i <= hi; i++) {
    int m = lo + (lo +hi)/2;
    int v = arr[m];

    if (v == n) {
      return m;
    } else if (v > n) {
      hi = m - 1;
    } else {
      lo = m + 1;
    }
  }
}

int  main() {
  int arr[] = {3, 4, 5, 6, 7, 9};
  int size = sizeof(arr) / sizeof(arr[0]);
  int n = 4;

  int result = binsearch(arr, n, size);
  printf("%d", result);
}
