#include <stdio.h>
#include <stdlib.h>
/*
 * Even though s1 and s2 reference the same string values, they're stored in 2 different memory addresses
 * The %p formats a memory address in hex
 * The right way to compare strings in C is to compare each character but that's a lot of extra code.
 * Fortunately, there's a string library that solves that for us (string.h).
 * Check out man string on Linux terminal
 * Next: string_strncp.c
 */
int main(int argc, char *argv[]) {
  char s1[] = "Navy";
  char s2[] = "Navy";

  if (s1 ==s2) {
    printf("Go  Navy!\n");
  } else{
    printf("Beat Army!\n");
  }

  printf("\n");
  printf("s1: %p \n", s1);
  printf("s2: %p \n", s2);
}
