#include <stdio.h>

int binsearch(int arr[], int size, int n) {
  int hi = size - 1;
  int lo = 0;

  for (int i = 0; i <= hi; i++) {
    int m = lo + (hi - lo) / 2;
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


