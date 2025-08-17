#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 100007
typedef struct {
  int key;
  int val;
  int used;
} entry_t;

int hash_func(int x) {
  return ((x % TABLE_SIZE) + TABLE_SIZE) % TABLE_SIZE;
}

int* two_sum_ii(int arr[], int k, int size) {
  entry_t* table = calloc(TABLE_SIZE, sizeof(entry_t));
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
