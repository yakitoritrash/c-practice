#include <stdio.h>
#include <stdlib.h>
#include <string.h

int getseclargest(int arr[], int size) {
  if (size < 2) {
    return -1;
  }

  int largest = arr[0];
  int second = -1;

  for (int i = 1; i < size; i++) {
    if (arr[i] > largest) {
      second = largest;
      largest = arr[i];
    } else if (arr[i] != largest && (second == -1 || arr[i] > second)) {
      second = arr[i];
    } 
  }

  if (second == -1) {
    printf("No second largest found\n");
    return -1;
  }

  printf("Second largest: %d\n", second);
  return second;
}


int main() {
  int arr[] = {4, 21, 4, 123, 56, 7, 43, 213, 67, 8, 62, 23, 68, 32, 90};
  int size = sizeof(arr) / sizeof(arr[0]);
  getseclargest(arr, size);
}
