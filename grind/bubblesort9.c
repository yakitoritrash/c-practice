#include <stdio.h>

void bubblesort(int arr[], int size) {
  for (int i = 0; i <= size - 1; i++) {
    for (int j = 0; j <= size - i - 1; j++) {
      if (arr[j] >= arr[j + 1]) {
        int tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
  }
}

int main() {
  int arr[] = {5, 4, 2, 1, 7, 6, 8, 9, 2};
  int size = sizeof(arr) / sizeof(arr[0]);
  bubblesort(arr, size);
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
}
