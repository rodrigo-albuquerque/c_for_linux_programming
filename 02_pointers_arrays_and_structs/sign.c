/* gettypesize */
/*
Implicitly all numeric types are signed and can have positive and negative representations.
Integer = 4 bytes, 1 bit is used for sign (+ or -)
so 31 bits are used for counting and largest signed int = 2^31  - 1.
Smallest int = 0 - 2^31.
We subtract 1 from largest value to account for zero.
%d with unsigned int = casting and because value overflows it prints -1
*/
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

  unsigned int i = 4294967295;

  printf("Char size in bytes: %lu\n", sizeof(char));
  printf("Short size in bytes: %lu\n", sizeof(short));
  printf("Int size in bytes: %lu\n", sizeof(int));
  printf("Long size in bytes: %lu\n", sizeof(long));
  printf("Float size in bytes: %lu\n", sizeof(float));
  printf("Double size in bytes: %lu\n", sizeof(double));
  printf("Pointer size in bytes: %lu\n", sizeof(char *));
  printf("Largest integer printed with unsigned: %u\n",i);
  printf("Largest integer printed without unsigned: %d\n",i);
}
