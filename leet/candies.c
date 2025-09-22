#include <stdio.h>

int candies(int arr[], int size) {

  int curr = 0;
  int res = 0;
  if (arr[1] < arr[0]) {
    res++;
  }
  if (arr[size] > arr[size - 1]) {
    res++;
  }

  for (int i = 1; i < size - 1; i++) {
    if (arr[i-1] < arr[i] && arr[i] > arr[i + 1]) {
      res++;
    }
  }
  res += size;
  return res;
}

int main() {
  int arr[] = {9, 10, 5, 1, 8, 2, 5, 2, 3, 7};
  int size = sizeof(arr) / sizeof(arr[0]);
  int res = candies(arr, size);
  printf("%d", res);
}
