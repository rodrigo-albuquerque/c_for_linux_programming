#include <stdio.h>
#include <stdlib.h>
/*
 * Moving through pointers, makes pointer jump X bytes where X = type of data (e.g. int = 4 bytes, char = 1 byte, etc).
 * Next: pointer_math2.c
 */
int main(int argc, char *argv[]) {
  int a[] = {0,1,2,3,4,5};
  char str[] = "Hello!";

  printf("a[3]:%d, str[3]:%c\n", *(a+3), *(str+3));
}
