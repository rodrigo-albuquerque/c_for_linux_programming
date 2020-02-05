#include <stdio.h>
#include <stdlib.h>

/*
 * Program assigns the address of a to p (character pointer).
 * Is having char * referenceing an integer wrong?
 * Pointer is just a memory address and memory address of an int or char is the same size (8 bytes).
 * So, who cares about it's called?
 * The pointer type impacts how we interpret the data the memory address references.
 * When we say &a we're providing a memroy address that references an integer.
 * When we interpret such memory address as char * instead, we can treat those 4 bytes of integer as 4 bytes of char array.
 * For printing: recall 2 hex-digits = one byte.
 * Our program s hould print 0x0a000000.
 * Wouldn't 0x0000000a make more sense?
 * Peobably, but to computers it doesn't really matter.
 */

int main(int argc, char *argv[]) {
  int a = 10; // declare an interger
  char * p = (char *) &a; // save address of interger as char *
  int i;
  printf("0x");
  for (i=0; i<4; i++) {
    printf("%02x", p[i]); // print the bytes of the integer in hex!
  }
  printf("\n");
}
