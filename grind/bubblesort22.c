#include <stdio.h>

void bubbblesort(int arr[], int size) {
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
  int arr[] = {23, 45, 12, 545, 12, 76, 23, 12, 76, 43, 89};
  int size = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]); 
  }

  printf("\n");

  bubbblesort(arr, size);

  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]); 
  }
}
