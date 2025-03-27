#include <stdio.h>
#include "cannonball.h"

int main() {
  cannonball_t c = new_cannonball(20, 10, 'A');
  
  printf("%d %d %c", c.x, c.y, c.z);
}
