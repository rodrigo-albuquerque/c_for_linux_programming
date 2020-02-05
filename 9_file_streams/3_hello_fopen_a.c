#include <stdio.h>
#include <stdlib.h>
/*
 *  Now the original "Hello World!" remains and additional "Hello World!" are appended to the end of the file.
 */
int main(int argc, char * argv[]) {
  FILE * stream = fopen("helloworld.txt", "a");
  fprintf(stream, "Hello World!\n");
  fclose(stream);
}
