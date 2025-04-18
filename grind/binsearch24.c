#include <stdio.h>

int binsearch(int arr[], int n, int size) {
  int hi = size - 1;
  int lo = 0;

  while (lo <= hi) {
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

int main() {
  int arr[] = {2, 3, 4, 5, 6, 9};
  int n = 9;
  int size = sizeof(arr) / sizeof(arr[0]);

  int result = binsearch(arr, n, size);

  printf("%d ", result);
}
