#include <stdio.h>
#include <stdlib.h>

typedef struct heap_t {
  int* arr;
  int size;
  int capacity;
} heap_t;

heap_t *create_heap(int capacity) {
  heap_t* heap = malloc(sizeof(heap_t));
  heap->size = 0;
  heap->capacity = capacity;
  heap->arr = malloc(sizeof(int) * capacity);
  return heap;
}

void swap(int *a, int *b) {

}
