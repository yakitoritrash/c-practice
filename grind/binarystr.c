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
    switch(op) {
      case 'A': result = result & val; break;
      case 'B': result = result | val; break;
      case 'C': result = result ^ val; break;
      default: return -1;
    }
    str++;
  }
  return result;
}

int main() {
  char expr[100];
  scanf("%99s", expr);
  int res = binarystr(expr);
  if (res != -1) {
    printf("result: %d\n", res);
  } else {
    printf("Invalid expression.\n");
  }
  return 0;
}
