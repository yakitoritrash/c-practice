#include <stdio.h>

void bubblesort(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
  }
}

int main() {
  int arr[] = {34, 12, 67, 34, 78, 342, 12, 543, 768, 234};
  int size = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < size; i++) {
    printf("%d ", aarr[i]);
  }

  printf("\n");

  bubblesort(arr, size);

  for (int i = 0; i < size; i++) {
    printf("%d ", aarr[i]);
  }
}
