#include <stdio.h>

int main(){

  
  int max_recursive_calls = 100;
  float throttle_speed = 0.2;
  int ports = 65535;
  char *hi = "hellooo";

  printf("Max recursive call: %d\n", max_recursive_calls); 
  printf("No. of Ports: %d\n", ports);
  printf("Throttle speed: %f\n", throttle_speed);
  printf("Hey there, %s\n", hi);
  return 0;

}
