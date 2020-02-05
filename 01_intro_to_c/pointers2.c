#include <stdio.h>
/*
Pointer is a data type whose value is a memory address.
A pointer must be declared based on what type it references.
For example, int * are pointers to integers and char * are pointers to chars.
int * p : pointer declaration
*p : pointer dereference, follow the pointer to the value
&a : Address of the variable a
p = &a : pointer assignment, p now references a
*p = 20 : assignment via a dereference, follow the pointer and assign a the value.
*/
int main(int argc, char *argv[]) {
  int x = 5, y;
  printf("x = %d;\n", x);
  printf("int *p = &x;\n");
  int *p = &x;
  printf("so, p = %d;\n", *p);
  printf("x = 10;\n");
  x = 10;
  printf("so, *p = %d;\n", *p);
  printf("x = *p;\n");
  y = *p;
  printf("so, y = %d;\n", y);
  printf("*p = 15;\n");
  *p = 15;
  printf("so, *p = %d and x = %d too\n", *p, x);
  printf("p = &y;\n");
  p = &y;
  printf("so p = %d;\n", *p);
}
