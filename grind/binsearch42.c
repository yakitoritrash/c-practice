#include <stdio.h>

int binsearch(int arr[], int size, int n) {
  int hi = size - 1;
  int lo = 0;
  while (lo <= hi) {
    int m = lo + (hi - lo) / 2;
    int v = arr[m];

    if (v == n) {
      return m;
    } else if (v > n) {
      m = hi - 1;
    } else {
      m = lo + 1;
    }
  }
  return -1;
}


