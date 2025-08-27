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

    }
  }
}
