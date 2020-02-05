#include <stdio.h>
#include <stdlib.h>
/*
 * Another interesting thing is that argv is NULL terminated just like strings.
 * Reason is just for OS to determine how many arguments are present, otherwise there'd be no way to know the end of the array.
 * When can use this fact when parsing the array by using pointer arithmetic and checking for a NULL reference.
 * Try executing with arguments: a b c d e
 */
int main(int argc, char *argv[]) {
  char ** curarg; // = pointer to a string (which is an array of chars), so it's a pointer to a pointer.
  int i;

  for ( curarg=argv, i=0; // Initialise curarg to argv array and i to 0, i.e. make curarg point to argv (which is also a pointer)
      *curarg != NULL;   // Stop when curarg references NULL
      curarg++, i++) {   // Increment curarg and i
    printf("argv[%d] = %s\n", i, *curarg);
  }
}
