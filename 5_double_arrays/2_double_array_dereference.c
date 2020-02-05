#include <stdio.h>
#include <stdlib.h>
/*
 *  Let's prove that a double array is a pointer that references a memory address that stores another pointer
 *  This other pointer  references a memory address that stores an Int.
 *  Remember that a pointer already points to the first item (this is why +2 goes to third item).
 */
int main(int argc, char *argv[]) {
  int darray[][4] = { { 0, 0, 0, 0 },
                      { 1, 1, 1, 1 },
                      { 2, 2, 2020, 2 },
                      { 3, 3, 3, 3 }
                    };
  printf("*(*(darray+2)+2) = %d\n", *(*(darray+2)+2));
  printf("    darray[2][2] = %d\n", darray[2][2]);
}
