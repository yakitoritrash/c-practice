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
  int* res = malloc(sizeof(int) * 2);
  for (int i = 0; i < size; i++) {
    int complement = k - arr[i];
    int hash = hash_func(complement);
    while (table[hash].used) {
      if (table[hash].key == complement) {
        res[0] = table[hash].val;
        res[1] = i;
        free(table);
        return res;
      }
      hash = (hash + 1) % TABLE_SIZE;
    }
    hash = hash_func(arr[i]);
    while (table[hash].used) {
      hash = (hash + 1) % TABLE_SIZE;
    }
    table[hash].used = 1;
    table[hash].key = arr[i];
    table[hash].val = i;
  }
  free(table);
  free(res);
  return NULL;
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
