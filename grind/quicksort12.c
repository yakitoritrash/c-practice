#include <stdio.h>

int partition(int arr[], int lo, int hi) {
  int pivot = arr[hi];
  int idx = lo - 1;

  for (int i = 0; i <= hi; i++) {
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
  int arr[] = {2, 1, 45, 34 ,132, 65, 343, 2, 1, 90, 67, 53, 89};
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
