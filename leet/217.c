#include <stdio.h>
#include <stdbool.h>

bool duplicates_in_arr(int arr[], int size) {
  for (int i = 0; i < size; i++) {

  }
  
}

int main() {
  int arr[] = {4, 5, 6, 8, 2, 3};
  int size = sizeof arr / sizeof arr[0];
  bool res = duplicates_in_arr(arr, size);
  printf("%d\n", res);
  return 0;
}
