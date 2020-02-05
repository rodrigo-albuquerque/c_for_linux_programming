#include <stdio.h>
#include <stdlib.h>

/*
 *  This program shows how to allocate memory to custom types
 *
 */

typedef struct {
  int left;
  int right;
} pair_t;

int main(int argc, char *argv[]) {
  pair_t * pairs = (pair_t *) calloc(10, sizeof(pair_t)); // an array of 10 pair_t's called pairs
  for (int i = 0; i < 10; i++) {
    pairs[i].right = i+1;
    pairs[i].left = i+10;
    printf("pairs[%d].right = %d, pairs[%d].left = %d\n", i, pairs[i].right, i, pairs[i].left);
  }
}
