#include <stdio.h>
#include <stdlib.h>
/*
 *  Just like previous program but with an array of pairs initialised.
 *  Try xxd -c 8 arraypair.txt
 *  We'll see 8 bytes printed per line.
 */
typedef struct {
  int left;
  int right;
} pair_t;

int main(int argc, char * argv[]) {
  pair_t pairs[10]; //we're not creeating an array
  int i;
  for (i=0; i<10; i++) {
    pairs[i].left = 10*i;
    pairs[i].right = 20*i;
  }

  FILE * stream = fopen("arraypair.txt","w");

  fwrite(pairs, sizeof(pair_t), 10, stream);

  fclose(stream);
}
