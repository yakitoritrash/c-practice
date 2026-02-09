include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
  return (*(int*)a - *(int *)b);
}

void findOriginal(int* original, int* new, int* indices, int numOfIndices, int compareSize) {
  for (int i = 0; i < numOfIndices; i += 1) {
    for (int j = 0; j < compareSize; j+= 1) {
      if (original[j] == new[indices[i]]) {
        if (i > 0 && indices[i - 1] == j) continue;
        indices[i] = j;
        break;
      }
    }
  }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
  int *numsCopy = malloc(sizeof(int) * numsSize);
  memcpy(numsCopy, nums, sizeof(int) * numsSize);
  qsort(numsCopy, numsSize, sizeof(int), cmp);
  int *res = malloc(sizeof(int) * 2);
  int j = numsSize - 1;
  int i = 0;
  while (i  < j) {
    if (numsCopy[i] + numsCopy[j] == target) {
      res[0] = i;
      res[1] = j;
      findOriginal(nums, numsCopy, res, 2, numsSize);
      *returnSize = 2;
      return res;
    }
    if (numsCopy[i] + numsCopy[j] < target) ++i;
    else --j;
  }
  return NULL;
}
