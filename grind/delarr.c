#include <stdio.h>

void del(int arr[], int *n, int key) {
  int i = 0;
  while (arr[i] != key) i++;
  for (int j = i; j < *n - 1; j++) {
    arr[j] = arr[j + 1];
  }

  (*n)--;
}

int main() {

}
