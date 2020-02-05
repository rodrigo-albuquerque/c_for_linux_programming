#include <stdio.h>
#include <stdlib.h>

/*
 * There are 2 major architectures to represent data: Big Endian and Little Endian.
 * Modern architecture use Little Endien where least significant bytes come before the more significant bytes.
 * This is backwards from how humans read numbers.
 * To prove this, let's print 0xdeadbeef by printing its individual bytes.
 */

int main(int argc, char *argv[]) {
  unsigned int a = 0xdeadbeef; // hex
  unsigned char * p = (unsigned char *) &a; // p points to a's mem address

  int i;
  printf("0x");
  for (i=0; i<4; i++) {
    printf("%02x",p[i]);
  }
  printf("\n");
}
