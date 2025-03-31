#include <stdio.h>

void strconcat(char *str1, char *str2) {
  int idx = 0;
  while (1) {
    if (str1[idx] == '\0') {
      break;
    }

    idx++;
  }

  int str2_pointer = 0;
  while (1) {
    str1[idx + str2_pointer] = str2[str2_pointer];

    if (str2[str2_pointer] == '\0') {
      return;
    }
    str2_pointer++;
  }

  //printf("Found null at %d for %s", idx, str1);

}


int main() {

  char *str1 = "hello";
  char *str2 = "lain";

  strconcat(str1, str2);
}
