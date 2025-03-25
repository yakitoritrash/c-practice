#include <stdio.h>

void bubblesort(int arr[], int n) {

  for (int i = 0; i <= n - 1; i++){
    for (int j = 0; j <= n - 1 - i; j++){
      if (arr[j] > arr[j+1]){
        int tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;
      }
    }
  }

}

int main(){
    int arr[] = {3, 2, 1, 5, 6, 4, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubblesort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
      printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;

}
