#include <stdio.h>
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

void free_map(hashmap_t *map) {
    for (int i = 0; i < HASH_SIZE; i++) {
        hashnode_t *current = map->buckets[i];
        while (current != NULL) {
            hashnode_t *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(map->buckets);
    free(map);
}

int hash(int key) {
    // Simple hash function
    return abs(key) % HASH_SIZE;
}

void put(hashmap_t *map, int key, int value) {
    int bucketIdx = hash(key);
    hashnode_t *current = map->buckets[bucketIdx];
    
    // Check if key already exists
    while (current != NULL) {
        if (current->key == key) {
            current->value = value;
            return;
        }
        current = current->next;
    }
    
    // Create new node
    hashnode_t *new_node = malloc(sizeof(hashnode_t));
    new_node->key = key;
    new_node->value = value;
    new_node->next = map->buckets[bucketIdx];
    map->buckets[bucketIdx] = new_node;
}

int get(hashmap_t *map, int key) {
    int index = hash(key);
    hashnode_t *current = map->buckets[index];
    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

int* twoSum(int *nums, int numsSize, int target, int* returnSize) {
    hashmap_t *map = create_map();
    *returnSize = 2;
    int *result = malloc(2 * sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int complementIdx = get(map, complement);
        if (complementIdx != -1) {
            result[0] = complementIdx;
            result[1] = i;
            free_map(map);
            return result;
        }
        put(map, nums[i], i);
    }
    
    free_map(map);
    free(result);
    *returnSize = 0;
    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    int *result = twoSum(nums, numsSize, target, &returnSize);
    if (result != NULL) {
        printf("[%d, %d]\n", result[0], result[1]);
        free(result);
    } else {
        printf("No solution found\n");
    }
    
    return 0;
}
