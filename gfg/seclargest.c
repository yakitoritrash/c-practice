#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//  int getseclargest(int arr[], int size) {
//    int compare(const void *a, const void *b) {
//
//    }
//
//    qsort(arr, size, sizeof(int), 1);
//  }


int partition(int arr[], int lo, int hi) {
  int pivot = arr[hi];
  int idx = lo - 1;

  for (int i = lo; i <= hi; i++) {
    if (arr[i] > pivot) {
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

int getseclargest(int arr[], int size) {
  quicksort(arr, size);
  return arr[1];
  printf("%d ", arr[1]);
}


int main() {
  int arr[] = {4, 21, 4, 213, 56, 7, 43, 123, 67, 8, 62, 23, 68, 32, 90};
  int size = sizeof(arr) / sizeof(arr[0]);
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");
  getseclargest(arr, size);
}
