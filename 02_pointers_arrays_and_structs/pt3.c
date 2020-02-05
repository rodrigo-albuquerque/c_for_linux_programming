#include <stdio.h>

int main(int argc, char *argv[]) {
  int x = 5;
  int *p = &x;
  x = 10;
  int y = *p;
  *p = 15;
  // new line added to previous example
  p = &y;
  printf("p is now pointing to y's memory address (%p) --> %d\n", p, *p);
}
