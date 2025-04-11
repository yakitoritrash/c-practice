#include <stdio.h>

void bubblesort(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        int tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
  }
}

int main() {
  int arr[] = {5, 32, 1, 5, 6, 8, 43, 12, 78, 34, 78, 12, 91, 99, 7};
  int size = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  bubblesort(arr, size);


  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
}
