#include <stdio.h>

int partition(int arr[], int lo, int hi){
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

void quicksort(int arr[], int size) {
  qs(arr, 0, size);
}
int main() {
  int arr[] = {5, 4, 2, 6, 7, 5, 1, 18, 9};
  int size = sizeof(arr) / sizeof(arr[0]) - 1;

  quicksort(arr, size);
  for (int i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
}
