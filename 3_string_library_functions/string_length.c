#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * string length: how many characters, not including null character, are in the string
 * sizeof: how many bytes required to store the string
 * E.g. "Hello!" has 6 letters (strlen) but its size is 7 bytes which includes null terminated character (char = 1 byte, remember?)
 * s has 8 bytes because it takes 1 byte to store the pointer itlsef + 7 bytes from string str.
 * So working with strings we'd probably be working with its length rather than size most of the times.
 * Next: printstr.c
 */
int main(int argc, char *argv[]) {
  char str[]="Hello!";
  char *s = str;

  printf("strlen(str):%d sizeof(str):%d sizeof(s):%d\n",
      (int) strlen(str), // str length
      (int) sizeof(str), // memory size of str
      (int) sizeof(s) // memory size of pointer
      );
}
