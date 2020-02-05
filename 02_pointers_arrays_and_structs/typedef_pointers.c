#include <stdio.h>

typedef struct {
  int left;
  int right;
} pair_t;

int main(int argc, char * argv[]) {
  pair_t pair;
  pair.left = 1;
  pair.right = 2;
  pair_t *p = &pair;
  // This:
  printf("pair: (%d,%d)\n", (*p).left, (*p).right);
  // Is the same as:
  printf("pair: (%d,%d)\n", p->left, p->right);
}
