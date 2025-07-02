#include <stdio.h>

int partition(arr, lo, hi) {
  int pivot = arr[hi];
  int idx = lo - 1;
  
  for (int i = 0; i < hi; i++) {
    if (arr[i] < pivot) {
      idx++;
      int tmp = arr[i];
      arr[i] = arr[idx];
      arr[idx] = tmp;
    }
  }

  idx++;
  arr[hi] = arr[idx];
  arr[idx] = pivot;

  return idx;
}


void qs(arr, lo, hi) {
  if (lo >= hi) {
    RETURNw
  }

}
