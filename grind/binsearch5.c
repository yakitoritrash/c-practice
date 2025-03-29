#include <stdio.h>

int binsearch(int haystack[], int needle, int size) {
  
  int hi = size;
  int lo = 0;

  for (int i = 0; i <= hi; i++) {
    int m = lo + (hi- lo)/2;
    int v = haystack[m];
    if (v == needle) {
      return m;
    } else if (v > needle) {
      hi = m - 1;
    } else {
      lo = m + 1;
    }
  }

  return -1;
}

int main() {
  int haystack[] = {3, 4, 5, 6, 7, 8};
  int size = sizeof(haystack) / sizeof(haystack[0]);
  int needle = 4;

  int result = binsearch(haystack, needle, size);
  printf("%d", result);
}
