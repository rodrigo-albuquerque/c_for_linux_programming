#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int *p = (int *) malloc(5*sizeof(int));
  p[0] = 10;
  p[1] = 20;
  p[2] = 30;
  p[3] = 40;
  p[4] = 50;
  for (int i = 0; i <= 4; i++) {
    printf("%d\n",p[i]);
  }
}

