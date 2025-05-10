#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//  int *twoSum(int arr[], int size, int target, int *returnsize) {
//    static int result[2];
//    for (int i = 0; i < size; i++) {
//      for (int j = 0; j < size; j++) {
//        if (arr[i] + arr[j] == target) {
//          result[0] = i;
//          result[1] = j;
//          *returnsize = 2;
//          return result;
//        }
//      }
//    }
//    *returnsize = 0;
//    return NULL;
//  }

#define HASH_LENGTH (32768)

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int map_key[HASH_LENGTH] = {0};
    int map_addr[HASH_LENGTH] = {0};
    bool map_used[HASH_LENGTH] = {false};
    int *retArray = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        int need = target - nums[i];
        int hash = (need % HASH_LENGTH + HASH_LENGTH) % HASH_LENGTH;

        while (map_used[hash]) {
            if (map_key[hash] == need) {
                *returnSize = 2;
                retArray[0] = map_addr[hash];
                retArray[1] = i;
                return retArray;
            }

        }

        int newHash = (nums[i] % HASH_LENGTH + HASH_LENGTH) % HASH_LENGTH;
        map_key[newHash] = nums[i];
        map_addr[newHash] = i;
        map_used[newHash] = true;
    }

    *returnSize = 0;
    return NULL;
}


int main() {
  int arr[] = {7, 3, 4, 5, 6, 8};
  int size = sizeof(arr) / sizeof(arr[0]);
  int target = 7;
  int returnsize;

  int *result = twoSum(arr, size, target, &returnsize);

  if (returnsize == 2) {
    for (int i = 0; i < 2; i++) {
      printf("%d ", result[i]);
    }
  } else {
    printf("Not found.\n");
    return -1;
  }
  return 0;
}

