#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 10000

typedef struct hashnode_t {
  char *key;
  int value;
  struct hashnode_t *next;
} hashnode_t;

typedef struct hashmap_t {
  hashnode_t* buckets[HASH_SIZE];
} hashmap_t;

hashmap_t *create_map() {
  hashmap_t *map = malloc(sizeof(hashmap_t));
  map->buckets = calloc(HASH_SIZE, sizeof(hashnode_t*));
  return map;
}
