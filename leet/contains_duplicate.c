#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}

bool contains_duplicate (int arr[], int size) {
  qsort(arr, size, sizeof(arr[0]), comp);
  for (int i = 0; i < size - 1; i++) {
    if (arr[i] == arr[i + 1]) {
      return true;
    }
  }
  return false;
}


int main() {
  int arr[] = {3, 4, 21, 12, 64, 6, 2};
  int size = sizeof(arr) / sizeof(arr[0]);
  int result = (int)contains_duplicate(arr, size);
  printf("%d", result);
}
