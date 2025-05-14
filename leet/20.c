#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char *s) {
  char stack[strlen(s)];
  int top = -1;

  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
      stack[++top] = s[i];
    } else {
      if (top == -1 ||
          (s[i] == ')' && stack[top] != '(') ||
          (s[i] == '}' && stack[top] != '{') ||
          (s[i] == ']' && stack[top] != '[')) {
        return false;
      }
      top--;
    }
  }
  return top == -1;
}

int main() {
  char *s = "{)";
  int result = (int)isValid(s);
  printf("%d",result);
}
