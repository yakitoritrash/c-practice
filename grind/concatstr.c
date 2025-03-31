#include <stdio.h>

void strconcat(char *str1, char *str2) {
  int idx = 0;
  while (true) {
    if (str[idx] == '/0') {
      break;
    }

    idx++;
  }
  printf("Found null at %d for %s", idx, str1);

}


int main() {

  char *str1 = "hello";
  char *str2 = "lain";

  strconcat(str1, str2);
}
