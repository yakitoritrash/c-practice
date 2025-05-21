#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASH_SIZE 10000

typedef struct hashnode_t {
  char *key;
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

int hash(char *key) {
  unsigned long hash = 0;
  int c;
  while ((c = *key++)) {
    hash = hash * 31 + c;
  }
  return hash % HASH_SIZE;
}

void put(hashmap_t *map, char *key, int value) {
  int bucketIdx = hash(key);
  hashnode_t *new_node = map->buckets[bucketIdx];
  if (new_node != NULL) {
    if (strcmp(new_node->key, key) == 0) {
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


