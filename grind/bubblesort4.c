#include <stdio.h>

void bubblesort(int arr[], int size) {
  for (int i = 0; i <= size; i++) {
    for (int j = 0; j <= size - i; j++) {
      if (arr[j] > arr[j+1]) {
        int tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;
      }
    }
  }
}

int main() {
  int arr[] = {1, 6, 4, 3, 7, 8, 2, 9, 2};
  int size = sizeof(arr) / sizeof(arr[0]) - 1;
  
  bubblesort(arr, size);
  for (int i = 0; i <= size; i++) {
    printf("%d ", arr[i]);
  }
}
