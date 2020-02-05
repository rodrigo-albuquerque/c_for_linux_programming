#include <stdio.h>

int main(int argc, char *argv[]) {
  int x = 5;
  int *p = &x;
  // new line added to previous example
  x = 10;
  int y = *p;
  *p = 15;
  printf("y remains %d even though *p was updated to 15 as y was not assigned a memory address but the actual value of *p at assignment time.\n",y);
}
