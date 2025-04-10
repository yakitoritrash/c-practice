#include <stdio.h>

int binsearch(int arr[], int size, int n) {
  int hi = size - 1;
  int lo = 0;

  for (int i = 0; i < hi; i++) {
    int m = lo + (hi - lo) / 2;
    int v = arr[m];

    if(v == n) {
      return m;
    } else if (v > n) {
      hi = m - 1;
    } else {
      lo = m + 1;
    }
  }
}

int main() {
  int arr[] = {3, 4, 5, 6, 7, 8 , 9};
  int size = sizeof(arr) / sizeof(arr[0]);
  int n = 5;

  int result = binsearch(arr, size, n);

  printf("%d ", result);
}
