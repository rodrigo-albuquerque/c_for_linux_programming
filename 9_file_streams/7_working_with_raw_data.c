#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int left;
  int right;
} pair_t;

int main(int argc, char * argv[]) {
  pair_t pair;
  FILE * stream = fopen("pair.txt", "r");
  fread(&pair, sizeof(pair_t), 1, stream);
  fclose(stream);
  printf("pair.left: %d pair.right: %d\n", pair.left, pair.right);
}
