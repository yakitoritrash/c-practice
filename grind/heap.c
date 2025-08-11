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

void buildheap(heap_t *heap) {
  int n = heap->size;
  for (int i = (n - 1) / 2; i >= 0; i--) {
    heapify(heap, i);
  }
}

void increasekey(heap_t *heap, int index, int newval) {
  if (index >= heap->size || heap->arr[index] >= newval) {
    printf("Invalid index pr new value is not greater.\n");
    return;
  }
  heap->arr[index] = newval;
  while (index != 0 && heap->arr[(index - 1) / 2] < heap->arr[index]) {
    swap(&heap->arr[index], &heap->arr[(index - 1) / 2]);
    index = (index - 1) / 2;
  }
}
