/*gettypesize.c*/
/*
 * sizeof(): uniquely used to report the amount of memory needed to hold a data element of that type.
 * we can pass a variable, but all it does is to report the amount of memory needed to store that variable's data.
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  printf("Char size in bytes: %lu\n", sizeof(char));
  printf("Short size in bytes: %lu\n", sizeof(short));
  printf("Int size in bytes: %lu\n", sizeof(int));
  printf("Short Int size in bytes: %lu\n", sizeof(short int));
  printf("Unsigned Int size in bytes: %lu\n", sizeof(unsigned int));
  printf("Long size in bytes: %lu\n", sizeof(long));
  printf("Float size in bytes: %lu\n", sizeof(float));
  printf("Double size in bytes: %lu\n", sizeof(double));
  printf("Pointer size in bytes: %lu\n", sizeof(char *));
}
