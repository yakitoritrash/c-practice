#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define alphabet 26
bool isAnagram(char *a, char *b) {
  if (strlen(a) != strlen(b)) {
    return false;
  }
  
  int hash1[alphabet] = {0};
  int hash2[alphabet] = {0};

  for (int i = 0; a[i] != '\0'; i++) {
    hash1[a[i] - 'a']++;
    hash2[b[i] - 'a']++;
  }
  for (int i = 0; i < alphabet; i++) {
    if (hash1[i] != hash2[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  char *a = "utah";
  char *b = "tuah";
  isAnagram(a, b);
}
