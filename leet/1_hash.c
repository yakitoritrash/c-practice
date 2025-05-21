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
