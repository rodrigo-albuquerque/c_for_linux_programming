#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 *  This program takes a string as input and write the string char-by-char to stdout using putchar() function.
 *  Next: different_sizes.c
 */
void my_puts(char * str) {
  while (*str) { // as long as char value is not false (i.e. not zero or null), loop keeps going
    putchar(*str); // printer character that pointer is currently on
    str++; // move pointer to next value
  }
}
/*
 * str is declared as char * which is a pointer to char
 * It is OK as pointers and arrays are the same  thing
 * str is a string that references 1st char in string's array *str operation is a dereference which follows the pointer and retrives the value it references.
 * In this case, it is a character value.
 */

int main(int argc, char *argv[]) {
  char str[20];
  printf("Enter a string to be repeated:\n");
  scanf("%s", str);
  my_puts(str);

}
/*
 * Takeaway here is that it's totally fine to work with arrays using indexing "[}" but when programmers work with strings, they ofen use pointer arithmentic
 */
