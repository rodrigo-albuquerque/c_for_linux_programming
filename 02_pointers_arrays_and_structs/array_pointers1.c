#include <stdio.h>
#include <stdlib.h>

/*
 *  This is to show that arrays and pointers are almost the same thing.
 *  *p = 2017 changes array[0]'s value to 2017
 *  So p is referencing the address of first item in the array and so is the array!
 */

int main (int argc, char *argv[]) {
  int array[10];
  int i;
  int *p = array; // p points to array
  // assign to array
  for (i=0; i<10; i++) {
    array[i] = 2*i; // index times 2
  }
  //dereference p and assign 2017
  *p = 2017;
  //print array
  for (i=0; i<10; i++) {
    printf("%d:%d\n",i, array[i]);
  }
}
