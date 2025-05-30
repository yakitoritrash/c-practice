#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASH_SIZE 10000

typedef struct hashnode_t {
  int key;
  int value;
  struct hashnode_t *next;
} hashnode_t;

typedef struct hashmap_t {
  hashnode_t **buckets;
} hashmap_t;

hashmap_t *create_map() {
  hashmap_t *map = malloc(sizeof(hashmap_t));
  map->buckets = calloc(HASH_SIZE, sizeof(hashnode_t*));
  return map;
}

int hash(int key) {
  unsigned long hash = 0;
  int c;
  while ((c = key++)) {
    hash = hash * 31 + c;
  }
  return hash % HASH_SIZE;
}

void put(hashmap_t *map, int key, int value) {
  int bucketIdx = hash(key);
  hashnode_t *new_node = map->buckets[bucketIdx];
  if (new_node != NULL) {
    if (new_node->key == key) {
      new_node->value = value;
      return;
    }
    new_node = new_node->next;
  }
  hashnode_t *new_node1 = malloc(sizeof(hashnode_t));
  new_node1->key = key;
  new_node1->value = value;
  new_node1->next = map->buckets[bucketIdx];
  map->buckets[bucketIdx] = new_node1;
}

int get(hashmap_t *map, int key) {
  int index = hash(key);
  hashnode_t *tmp = map->buckets[index];
  while (tmp != NULL) {
    if (tmp->key == key) {
      return tmp->value;
    }
    tmp = tmp->next;
  }
  return -1;
}

int twoSum(int *nums, int numsSize, int target, int* returnSize) {
  hashmap_t *map = create_map();
  *returnSize = 2;
  int *result = (int*)malloc(2 * sizeof(int));

  for (int i = 0; i < numsSize; i++) {
    int complement = target - nums[i];
    int complementIdx = get(map, complement);
    if (complementIdx != -1) {
      result[0] = complementIdx;
      result[1] = i;
    }
    put(map, nums[i], i);
  }
  return -1;
}

int main() {
  int nums[] = {2, 7, 11, 15};
  int target = 9;
  int returnSize;
  int numsSize = sizeof(nums) / sizeof(nums[0]);
  int *result = (&int)twoSum(nums, numsSize, target, &returnSize);
  printf("[%d, %d]", result[0], result[1]);
  free(result);
}
