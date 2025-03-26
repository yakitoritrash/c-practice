#include <stdio.h>

int partition(int arr[], int lo, int hi) {
  int pivot = arr[hi];
  int idx = lo - 1;

  for (int i = lo; i < hi; i++) {
    if (arr[i] <= pivot) {
      idx++;
      int tmp = arr[i];
      arr[i] = arr[idx];
      arr[idx] = tmp;
    }
  }

  idx++;
  arr[hi] = arr[idx];
  arr[idx] = pivot;

  return idx;
}

void qs(int arr[], int lo, int hi) {
  if (lo >= hi) {
    return;
  }

  int pivotIdx = partition(arr, lo, hi);
  qs(arr, lo, pivotIdx - 1);
  qs(arr, pivotIdx + 1, hi);
}

int quicksort(int arr[], int n) {
  qs(arr, 0, n - 1);
}

int main() {
  int arr[] = {4, 3, 2, 6, 5, 7, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  quicksort(arr, n);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}


