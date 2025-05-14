#include <stdio.h>

#define alphabets[26];

int lengthAfterTrans(char *s, int t) {
  for (int i = 0; i < t; i++) {
    if (s[i] == "z") {
      s[i] = "ab";
    }
  }
}
