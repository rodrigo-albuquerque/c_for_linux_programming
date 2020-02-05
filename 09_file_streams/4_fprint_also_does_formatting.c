#include <stdio.h>
#include <stdlib.h>
/*
 * Try ./4_fprint_also_does_formatting a b c d e f
 */
int main(int argc, char *argv[]) {
  int i;
  FILE * stream = fopen("cmd.txt", "w");
  for (i=0; i<argc; i++) {
    fprintf(stream, "argv[%d] = %s\n", i, argv[i]);
  }
  fclose(stream);
  return 0;
}
