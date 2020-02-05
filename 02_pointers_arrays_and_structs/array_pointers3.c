#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int a[10];
  int b[10];
  int *p;
  // pointers can be reassigned like any other variable
  p = a; // ok
  // arrays can't as they're constants
  b = p; // not ok
}
