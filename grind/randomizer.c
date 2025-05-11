#include <stdio.h>
#include <time.h>

unsigned int seed;

unsigned int my_random() {
  seed = (1103515245 * seed + 12345) % (1U << 31);
  return seed;
}

char* random(char* arr[], int size) {
  unsigned int r = my_random();
  int index = r % size;
  return arr[index];
}

int main() {

  seed = (unsigned int)time(NULL);
  char* arr[] = {"jurrasic", "lego batman"};
  int size = sizeof(arr) / sizeof(arr[0]);

  const char *movie = random(arr, size);
  printf("%s", movie);


  return 0;
}
