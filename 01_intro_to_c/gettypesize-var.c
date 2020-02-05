/* gettypesize */
/*
The same basic numeric types exist in C:
int : integer number : 4-bytes
short : integer number : 2-bytes
long : integer number : 8-bytes
char : character : 1-byte
float : floating point number : 4-bytes
double : floating point number : 8-bytes
void * : pointers : 8-bytes on (64 bit machines)
--> Important in C data must be stored in memory,
so, we must know how much memory is needed to store data
*/
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
  char c=0;
  short s=0;
  int i=0;
  long l=0;

  float f=0;
  double d=0;

  char *p=0;

  printf("Char size in bytes: %lu\n", sizeof(c));
  printf("Short size in bytes: %lu\n", sizeof(s));
  printf("Int size in bytes: %lu\n", sizeof(i));
  printf("Long size in bytes: %lu\n", sizeof(l));
  printf("Float size in bytes: %lu\n", sizeof(f));
  printf("Double size in bytes: %lu\n", sizeof(d));
  printf("Char size in bytes: %lu\n", sizeof(p));

}
