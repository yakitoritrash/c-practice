#include <stdio.h>

int binsearch(int arr[], int size, int n) {
  int hi = size - 1;
  int lo = 0;

  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    int v = arr[mid];
    if (v == n) {
      return mid;
    } else if (v > n) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return -1;
}

int main() {
  int arr[] = {2, 3, 4, 5, 7, 8, 9};
  int size = sizeof(arr) / sizeof(arr[0]);
  int n = 7;
  int result = binsearch(arr, size, n);
  printf("%d", result);
}
