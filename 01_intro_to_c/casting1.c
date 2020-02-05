#include <stdio.h>

int main(int argc, char *argv[]) {
  int i = 1847;
  float f = i; // integer to float

  printf("int to float: f: %f\n",f);

  float g = 3.1415926;
  int j = g; // float to integer

  printf("float to int: j: %d\n", j);
}
