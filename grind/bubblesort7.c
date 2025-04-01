#include <stdio.h>

void bubblesort(int arr[], int size) {
  for (int i = 0; i <= size; i++) {
    for (int j = 0; j <= size - i; j++) {
      if (arr[j] >= arr[j+1]) {
        int tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;
      }
    }
  }
}

int main() {
  int arr[] = {4, 2, 1, 4, 6, 5, 7, 1};
  int size = sizeof(arr) / sizeof(arr[0]) - 1;
  
  bubblesort(arr, size);
  for (int i = 0; i <= size; i++) {
    printf("%d ", arr[i]);
  }
}
