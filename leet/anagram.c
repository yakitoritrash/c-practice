#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define alphabet 26

bool anagram(char *t, char *s) {
  if (strlen(t) != strlen(s)) {
    return false;
  }
  int hash1[alphabet] = {0};
  int hash2[alphabet] = {0};
  for (int i = 0; s[i] != '\0'; i++) {
    hash1[s[i] - 'a']++;
    hash1[t[i] - 'a']--;
  }
  for (int i = 0; i < alphabet; i++) {
    if (hash1[i] != hash2[i]) {
      return false;
    }
  }
  return true;
}
int main() {
  char s[1000];
  fgets(s, 1000, stdin);
  char t[1000];
  fgets(t, 1000, stdin);
  int res = anagram(s, t);
  printf("%d", res);
}
