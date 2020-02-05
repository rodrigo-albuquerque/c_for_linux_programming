#include <stdio.h>
/*
 *  typedef hides the struct behind it using names
*/

typedef struct {
  int left;
  int right;
} pair_t; // type  name for new structure is pair_t

int main(int argc, char *argv[]) {
  pair_t p1; // declaring  variables of that type
  pair_t p2;
  p1.left = 10; // assign values to pair types
  p1.right = 20;
  p2.left = 0;
  p2.right = 5;
  printf("p1.left: %d and p1.right: %d\n", p1.left, p1.right);
  printf("p2.left: %d and p2.right: %d\n", p2.left, p2.right);
}
