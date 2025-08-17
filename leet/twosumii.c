#include <stdio.h>
#include <stdlib.h>

#define HASH_TABLE 100007
int* two_sum_ii(int arr[], int k, int size) {

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
