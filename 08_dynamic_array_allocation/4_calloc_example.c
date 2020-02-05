#include <stdio.h>
#include <stdlib.h>

/*
 * malloc() is multi-purpose allocation tool so to allocate an array of right size, we have to perform an arithmetic computation like 20*sizeof(int).
 * calloc() address this issue with an additional argument:
 *  The number of items
 *  to be allocated      --.
 *                         |
 *                         v
  int * a = (int *) calloc(20, sizeof(int));
 *                                  ^
 *                                  |
 *                            The size of each item
 *  calloc() also zeroes-out or clean the memory that is allocated.
 */

int main(int argc, char *argv[]) {
  int * a = (int *) calloc(20, sizeof(int));
  int i;
  for (i = 0; i < 20; i++) {
    printf("%d\n",a[i]); // calloc zeroes-out allocated memory
  }
}
// if we run above program, it should print all 0's when compareed to malloc in our previous example
