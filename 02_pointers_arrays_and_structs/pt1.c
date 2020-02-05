#include <stdio.h>

int main(int argc, char *argv[]) {
  int x = 5;
  int *p = &x;
  printf("p holds %p memory address which points to the same value as x (%p) which is %d\n", p,&x,*p);
}
