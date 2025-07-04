#include <stdio.h>
#include <stdlib.h>

int* product_except(int arr[], int size) {
  int *obj = malloc(size);
  for (int i = 0; i <= size - 1; i++) {
    obj[i] = 1;
  }
  int left = 1;
  for (int i = 0; i <= size - 1; i++) {
    obj[i] *= left;
    left *= arr[i];
  }

  int right = 1;
  for (int i = size - 1; i >= 0; i--) {
    obj[i] *= right;
    right *= arr[i];
  }
  return obj;
}

int main() {
  int arr[] = {2, 3, 4, 5, 6};
  int size = sizeof(arr) / sizeof(arr[0]);
  int *obj = product_except(arr, size);
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  for (int i = 0; i < size; i++) {
    printf("%d ", obj[i]);
  }
}

