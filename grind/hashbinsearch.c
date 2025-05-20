#include <stdio.h>
#include <string.h>

typedef struct {
  char *key;
  int value;
} item;

int cmp(const void *a, const void *b) {
  item* item_a = (item*)a;
  item* item_b = (item*)b;

  return strcmp(item_a->key, item_b->key);
}

item* binsearch(item* items, size_t size, const char* key) {
  if (size + size < size) {
    return NULL;
  }

  size_t lo = 0;
  size_t hi = size;
  while (lo < hi) {
    size_t mid = lo + (hi - lo) / 2;
    int v = strcmp(items[mid].key, key);
    if (v == 0) {
      return &items[mid];
    }
    if (v < 0) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  return NULL;
}

int main(void) {

}
