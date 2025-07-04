#include <stdio.h>
#include <stdlib.h>

int* two_sum_ii(int arr[], int k, int size) {
  int* res = malloc(2 * sizeof(int));

  int left = 0;
  int right = size - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == k) {
      res[0] = left + 1;
      res[1] = right + 1;
      return res;
    } else if (sum > k) {
      right--;
    } else {
      left++;
    }
  }
  free(res);
  return NULL;
}

int main() {
  int arr[] = {2, 7, 11, 12, 14};
  int size = sizeof(arr) / sizeof(arr[0]);
  int k = 9;
  int* res= two_sum_ii(arr, k, size);
  for (int i = 0; i < 2; i++) {
    printf("%d ", res[i]);
  }
}
