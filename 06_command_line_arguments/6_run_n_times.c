#include <stdio.h>
#include <stdlib.h>
/*
 *  Here we check if argc < 2 that means we didn't provide any arguments so we throw an error.
 */
int main(int argc, char *argv[]) {
  int i;
  int n;

  if (argc < 2) {
    fprintf(stderr, "ERROR: invalid number of arguments\n");
    exit(1); // exits program
  }

  if ( sscanf(argv[1], "%d", &n) == 0 ) {
    fprintf(stderr, "ERROR: require a number\n");
    exit(1); //exit the program
  }

  for (i=0; i<n; i++) {
    printf("%s\n", argv[2]);
  }
}
