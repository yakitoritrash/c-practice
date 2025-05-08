#include <stdio.h>

int *twoSum(int arr[], int size, int target, int *returnsize) {
  static int result[2];
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (arr[i] + arr[j] == target) {
        result[0] = i;
        result[1] = j;
        *returnsize = 2;
        return result;
      }
    }
  }
  *returnsize = 0;
  return NULL;
}

int main() {
  int arr[] = {7, 3, 4, 5, 6, 8};
  int size = sizeof(arr) / sizeof(arr[0]);
  int target = 7;
  int returnsize;

  int *result = twoSum(arr, size, target, &returnsize);

  if (returnsize == 2) {
    for (int i = 0; i < 2; i++) {
      printf("%d ", result[i]);
    }
  } else {
    printf("Not found.\n");
    return -1;
  }
  return 0;
}
