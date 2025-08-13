#include <stdio.h>

int binarystr(char *str) {
  if (!str || !(*str == '0' || *str == '1')) {
    return -1;
  }
  int result = *str - '0';
  str++;

  while (*str) {
    char op = *str++;
    if (!*str) return -1;

    int val = *str - '0';
    if (val != 0 && val != 1)
      return -1;
  }
}
