#include <stdio.h>
#include <stdlib.h>
/*
 *  If we execute it 2x, we can see that file is overwritten!
 */
int main(int argc, char * argv[]) {
  FILE * stream = fopen("helloworld.txt", "w");
  fprintf(stream, "Hello World!\n");
  fclose(stream);
}
