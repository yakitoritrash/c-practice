#include <stdio.h>

int binsearch(int arr[], int size, int n) {
  int hi = size - 1;
  int lo = 0;

  while (lo <= hi) {
    int m = lo + (hi - l0) / 2;
    int v = arr[m];

    if (v == n) {
      return m;
    } else if (v > n) {
      hi = m - 1;
    } else {
      lo = m + 1;
    }
  }
}

int main() {

}
