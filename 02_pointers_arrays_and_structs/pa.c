#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
  int A[5];
  printf("A's memory address: %p\n", &A);
  int n;
  printf("n's memory address: %p\n", &n);
  int *p = A; // p is now pointing to same memory address of A
  printf("p is now pointing to %p which is A's memory address\n", p);
  p = &n;     // this is fine as pointers can be re-assigned to different memory address
  printf("p now points to %p which is n's memory address\n", p);
  //A = n;     // this is not
}
