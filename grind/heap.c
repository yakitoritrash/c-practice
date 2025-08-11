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
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void heapify(heap_t *heap, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < heap->size && heap->arr[left] > heap->arr[largest]) {
    largest = left;
  }
  if (right < heap->size && heap->arr[right] > heap->arr[largest]) {
    largest = right;
  }
  if (largest != i) {
    swap(&heap->arr[i], &heap->arr[largest]);
    heapify(heap, largest);
  }
}
