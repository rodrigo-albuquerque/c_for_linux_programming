#include <stdio.h>

int main(int argc, char *argv[]) {
  float pi = 3.1415926; //pi
  float e = 2.7182818; //e
  float r2 = 1.1412135; //root 2

  int k = pi + e + r2; // casts on assignment
  int l = (int) pi + (int) e + (int) r2; //casts  before operations

  printf("cast on assingment: k: %d\n", k);
  printf("cast before operation: l: %d\n", l);
}
