#include <stdio.h>

int partition(int arr[], int lo, int hi) {
  int pivot = arr[hi];
  int idx = lo - 1;

  for (int i = lo; i < hi; i++) {
    if (arr[i] < pivot) {
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

void quicksort(int arr[], int size) {
  qs(arr, 0, size - 1);
}

int main() {
  int arr[] = {432, 156, 123, 565, 23, 4, 6, 243, 98, 1223, 8989};
  int size = sizeof(arr) / sizeof(arr[0]);

}
