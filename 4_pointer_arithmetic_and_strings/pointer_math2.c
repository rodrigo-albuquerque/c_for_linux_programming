#include <stdio.h>
#include <stdlib.h>
/*
 * a+3 moves pointer 12 bytes (int = 4 bytes)
 * str+3 moves pointer 3 bytes (char = 1 byte)
 * Both cases the memory address is different
 * Next: pointer_casting.c
 */
int main(int argc, char *argv[]) {
  int a[] = {0,1,2,3,4,5};
  char str[] = "Hello!";

  printf("a[3]:%d str[3]:%c\n", *(a+3),*(str+3));

  printf("a=%p a+3=%p (a+3-a)=%d\n",
      a,
      a+3,
      (int) (a+3) - (int) a
      );

  printf("str=%p str+3=%p (str+3-str)=%d\n",
      str,
      str+3,
      (int) (str+3) - (int) str
      );
}
