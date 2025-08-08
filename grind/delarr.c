#include <stdio.h>

void del(int arr[], int *n, int key) {
  int i = 0;
  while (arr[i] != key) i++;
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
  int size = sizeof(arr) / sizeof(arr[0]);
  int key;
  scanf("%d", &key);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  del(arr, &size, key);
  for (int i = 0; i < n - 1; i++) {
    printf("%d ", arr[i]);
  }
}
