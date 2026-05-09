#include <stdio.h>

int main() {
  int counter = 0;
  int result = 0;
  while (counter < 10) {
    counter++;
  }
  result = counter * 2;
  printf("result: %d, counter: %d", result, counter);
}
