#include <stdio.h>

void deletefromarr(int arr[], int *n, int del) {
  int i = 0;
  while (arr[i] != del) i++; 
  for (int j = i; j < *n - 1; j++) {
    arr[j] = arr[j + 1];
  }
  (*n)--;
}

int main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  int x;
  scanf("%d", &x);
  int size = sizeof(arr) / sizeof(arr[0]);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  deletefromarr(arr, &size, x);
  for (int i = 0; i < n - 1; i++) {
    printf("%d ", arr[i]);
  }
}
