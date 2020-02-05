#include <stdio.h>
/*
 * int  * p: pointer declaration
 * *p: pointer dereference, follow the pointer to the value
 * &a: address of variable a
 * p = &a : pointer assignment, p now references a.
 * *p = 20 : assignment via dereference, follow pointer and assign 20 to a.
*/

int main(int argc, char *argv[]) {
  int a = 10;
  printf("a = %d\n",a);
  int *p = &a;
  *p = 20;
  printf("p =  &a;\n*p = 20;\nNow, a = %d\n", a);
}
