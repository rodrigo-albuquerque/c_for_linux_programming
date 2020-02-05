#include <stdio.h>
#include <stdlib.h>
/*
 *  Each index of the array references another array (int **),
 *  i.e. pointer that references a memory address that stores another pointer that references a memory address of an Integer.
 *  Here's a visual of the stack diagram:
                           .---.---.---.---.
            .---.  _.----> | 0 | 0 | 0 | 0 |  <-- darray[0]
darray ---> | --+-'        '---'---'---'---'
            |---|          .---.---.---.---.
            | --+--------> | 1 | 1 | 1 | 1 |  <-- darray[1]
            |---|          '---'---'---'---'
            | --+-._       .---.---.---.---.
            |---|   '----> | 2 | 2 | 2 | 2 |  <-- darray[2]
            | --+-._       '---'---'---'---'
            '---'   '._    .---.---.---.---.
                       '-> | 3 | 3 | 3 | 3 |  <-- darray[3]
                           '---'---'---'---'
 *  When we say double array, we're also referring to double pointers.
 *  We must define the size of the inner arrays.
 *  Next: 2_double_array_dereference.c
 */
int main (int argc, char *argv[]) {
  int darray[][4] = { { 0, 0, 0, 0 },
                      { 1, 1, 1, 1 },
                      { 2, 2, 2, 2 },
                      { 3, 3, 3, 3 }
                    };
  int i,j;

  for (i=0; i<4; i++) {
    printf("darray[%d] = { ",i);
    for (j=0; j<4; j++) {
      printf("%d ", darray[i][j]);
    }
    printf("}\n");
  }
}
