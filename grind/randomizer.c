#include <stdio.h>


unsigned int seed = 123456789;

unsigned int my_random() {
  seed = (1103515245 * seed + 12345) % (1 << 31);
  return seed;
}

char* random(char* arr[], int size) {
  unsigned int r = my_random();
  int index = r % size;
  return arr[index];
}

int main() {
  char* arr[] = {"jurrasic", "lego batman"};
  int size = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < 5; i++) {
    const char *movie = random(arr, size);
    printf("%s", arr);
  }

  return 0;
}
