#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct entry_t {
  char* key;
  int value;
  struct entry_t *next;
} entry_t;

typedef struct hash_map {
  entry_t **buckets;
  int capacity;
} hash_map;

int hash(char* str, int capacity) {
  unsigned long hash = 0;
  int c;
  while ((c = *str++)) {
    hash = hash * 31 + c;
  }
  return hash % capacity;
}

hash_map *create_map(int capacity) {
  hash_map *map = malloc(sizeof(hash_map));
  if (!map) return NULL;
  map->buckets = calloc(capacity, sizeof(entry_t*));
  if (!map->buckets) {
    free(map);
    return NULL;
  }
  map->capacity = capacity;
  return map;
}

void put(hash_map *map, char* key, int value) {
  int bucketIdx = hash(key, map->capacity);
  entry_t *entry = map->buckets[bucketIdx];
  if (entry != NULL) {
    if (strcmp(entry->key, key) == 0) {
      entry->value = value;
      return;
    }
    entry = entry->next;
  }
  entry_t *new_entry = malloc(sizeof(entry_t));
  new_entry->key = strdup(key);
  new_entry->value = value;
  new_entry->next = map->buckets[bucketIdx];
  map->buckets[bucketIdx] = new_entry;
}

void get(hash_map *map, char *key) {
  int bucketIdx = hash(key, map->capacity);
  entry_t 
}


