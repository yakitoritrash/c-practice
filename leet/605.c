#include <stdio.h>
#include <stdbool.h>

bool flowerBed(int flowerbed[], int flowerbedsize, int n) {
  for (int i = 0; i < flowerbedsize && n > 0; i++) {
    if (flowerbed[i] == 0) {
      int prev = (i == 0) ? 0 : flowerbed[i - 1];
      int next = (i == flowerbedsize - 1) ? 0 : flowerbed[i + 1];

      if (prev == 0 && next == 0) {
        flowerbed[i] = 1;
        n--;
      }
    }
  }
  return n <= 0;
}

int main() {
  int flowerbed[] = {1, 0, 0, 0, 1};
  int flowerbedsize = sizeof(flowerbed) / sizeof(flowerbed[0]);
  int n = 1;
  int result = (int)flowerBed(flowerbed, flowerbedsize, n);
  printf("%d", result);
}
