#include <stdio.h>
#include <stdlib.h>
/*
 * This is the fix for string_declarations.c
 * When we add characters to "", the extra NULL char is automatically appended to the end
 * Next: format_string.c
 */
int main(int argc, char *  argv[]) {

  char a[] = "Go Navy!";
  char b[10] = "Go Navy!";
  int i;

  printf("sizeof(a):%d   sizeof(b):%d\n",
      (int) sizeof(a),
      (int) sizeof(b)
      );

  printf("\n");
  for(i=0;i<9;i++) {
    //print char and ASCII value
    printf("a[%d]: %c (%d)\n",i,a[i],a[i]);
  }

  printf("\n");
  for(i=0;i<10;i++) {
    //print char and ASCII value
    printf("b[%d]: %c (%d)\n",i,b[i],b[i]);
  }

  printf("\n");
  printf("a: %s\n",a); //format print the string
  printf("b: %s\n",b); //format print the string
}
