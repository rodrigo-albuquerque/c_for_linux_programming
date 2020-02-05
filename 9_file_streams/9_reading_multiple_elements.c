#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int left;
  int right;
} pair_t;

int main(int argc, char * argv[]) {
  pair_t pairs[10];

  FILE * stream = fopen("arraypair.txt", "r");

  fread(pairs, sizeof(pair_t), 10, stream);

  int i;
  for (i=0; i<10; i++) {
    printf("pair.left: %d pair.right: %d\n",pairs[i].left, pairs[i].right);
  }
  fclose(stream);
}
