#include <stdio.h>
#include <stdlib.h>

int cmp(const void *p1, const void *p2) {
  return (*(int *) p1 - *(int *)p2); 
}

int** threesum(int arr[], int size, int* returnSize) {
  qsort(arr, size, sizeof(arr[0]), cmp);
  int** res = malloc(size * sizeof(int*));
  *returnSize = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] > 0) {
      break;
    }
    if (i > 0 && arr[i] == arr[i - 1]) continue;
    int left = i + 1;
    int right = size - 1;
    while (left < right) {
      int sum = arr[i] + arr[left] + arr[right];
      if (sum == 0) {
        res[*returnSize][0] = arr[i];
        res[*returnSize][1] = arr[left];
        res[*returnSize][2] = arr[right];
        (*returnSize)++;
        left++;
        right--;
      } else if (sum > 0) {
        right--;
      } else {
        left++;
      }
    }
  }
  return res;
}

int main() {
  int arr[] = {-1, -1, 0, 2, -4};
  int size = sizeof(arr) / sizeof(arr[0]);
  int returnSize;
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  int** result = threesum(arr, size, &returnSize);
  for (int i = 0; i < size; i++) {
    printf("%d %d %d", result[i][0], result[i][1], result[i][2]);
  }
}
