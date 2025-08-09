#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
  return (*(int*)a - *(int*)b);
}
bool condupe(int arr[], int size) {
  qsort(arr, size, sizeof(int), compare);
  for (int i = 0; i < size; i++) {
    if (arr[i] == arr[i + 1]){
      return true;
    }
  }
  return false;
}
int main() {
  int arr[] = {3, 8, 4, 5, 6, 7, 8};
  int size = sizeof(arr) / sizeof(arr[0]);
  int res = condupe(arr, size);
  printf("%d", res);
}
