#include  <stdio.h>
#include <stdlib.h>
/*
 * scanf stops at space, so "Rodrigo Farias" will print "Rodrigo" only
 * longer than 20 characters will cause segmentation fault when it tries to read/access a portion of memory that is not allocated
 * Next: string_badcmp.c
 */
int main(int  argc, char *argv[]) {
  char name[20];

  printf("What is your name?\n");
  scanf("%s",name);

  printf("\n");
  printf("Hello %s!\n",name);
}
