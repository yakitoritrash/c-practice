#include <stdio.h>
#include <stdbool.h>

//  bool duplicates_in_arr(int arr[], int size) {
//    for (int i = 0; i < size; i++) {
//      for (int j = i + 1; j < size; j++) {
//        if (arr[i] == arr[j]) {
//          return true;
//        }
//      }
//    }
//    return false;
//  }

int partiton(int arr[], int lo, int hi) {
  int pivot = arr[hi];
  int idx = lo - 1;
  for (int i = lo - 1; i <= hi; i++) {
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
  int pivotIdx = partiton(arr, lo, hi);
  qs(arr, lo, pivotIdx - 1);
  qs(arr, pivotIdx + 1, hi);
}

void quicksort(int arr[], int size) {
  qs(arr, 0, size - 1);
}


bool duplicates_in_arr(int arr[], int size) {
  quicksort(arr, size);
  for (int i = 0; i < size; i++) {
    if (arr[i] == arr[i+1]) {
      return true;
    }
  }
  return false;
}

int main() {
  int arr[] = {9, 3, 5, 6, 8, 2, 3};
  int size = sizeof arr / sizeof arr[0];
  bool res = duplicates_in_arr(arr, size);
  printf("%d\n", res);
  return 0;
}
