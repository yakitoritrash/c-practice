#include <stdio.h>

int partition(int arr[], int lo, int hi) {
  int pivot = arr[hi];
  int idx = lo - 1;

  for (int i = lo; i <= hi; i++) {
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
  int arr[] = {34, 12, 65, 6, 123, 878, 4, 2, 6, 123, 6, 89, 10};
  int size = sizeof(arr) / sizeof(arr[0]);
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  
  printf("\n");
  quicksort(arr, size);

  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
}
