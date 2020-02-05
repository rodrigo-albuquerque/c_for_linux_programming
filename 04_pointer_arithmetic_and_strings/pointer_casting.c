#include <stdio.h>
#include <stdlib.h>
/*
 *  This is how to access individual bytes of larger data types
 *  Next: 5
 */
int main(int argc, char *argv[]) {
  char s[4];

  s[0] = 255;
  s[1] = 255;
  s[2] = 255;
  s[3] = 255;
  // We're declaring pointer *i that references same memory as s but looks at it as int (implicit conversion)
  // When we grab 255 which is all 1's and turn into signed int, it becomes -1 (in two's complement)
  int * i = (int *) s;
  printf("*i = %d\n", *i);
}
/*
 * We used pointer casting to determine how to interpret the data so char is effectively a generic container
 * Character arrays are referred to as buffers because of this property of being arbitrary containers
 * A buffer of data is just a bunch of bytes and character array is the most direct way to access that data
 */
