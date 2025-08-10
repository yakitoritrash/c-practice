#include <stdio.h>

void remarr(int arr[], int *n, int needle) {
  int i = 0;
  while (i != needle) i++;
  for (int j = i; j < *n; j++) {
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
  for (int i = 0; i < n; i++) {
    printf("%d", arr[i]);
  }
  printf("\n");
  remarr(arr, &n, x);
  for (int i = 0; i < n - 1; i++) {
    printf("%d", arr[i]);
  }
}
