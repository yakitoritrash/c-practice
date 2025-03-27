#include "cannonball.h"

cannonball_t new_cannonball(int x, int y, char z) {
  cannonball_t c = {
    .x = x,
    .y = y,
    .z = z,
  };

  return c;
}
