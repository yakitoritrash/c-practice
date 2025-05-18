#include <stdio.h>

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

