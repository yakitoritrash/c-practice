#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
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


int compare(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}

bool duplicates_in_arr(int arr[], int size) {
  qsort(arr, size, sizeof(int), compare);
  for (int i = 0; i < size; i++) {
    if (arr[i] == arr[i + 1]) {
      return true;
    }
  }
  return false;
}

int main() {
  int arr[] = {9, 3, 5, 6, 8, 9, 2};
  int size = sizeof arr / sizeof arr[0];
  bool res = duplicates_in_arr(arr, size);
  printf("%d\n", res);
  return 0;
}
