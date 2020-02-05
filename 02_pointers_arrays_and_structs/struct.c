#include <stdio.h>
/*
 * struct pair
.--------------------.
|.--------..--------.|
||<- 4B ->||<- 4B ->||
||  left  ||  right ||
|'________''________'|
'--------------------'
 <----- 8 bytes ----->
 *
 */
int main(int argc, char *argv[]) {
  struct pair {
    int left;
    int right;
  };

  struct pair p1;
  struct pair p2;
  printf("size of pair: %lu bytes\n", sizeof(struct pair));
  p1.left = 10;
  p1.right = 20;
  printf("p1.left: %d and p1.right: %d\n", p1.left, p1.right);
  p2.left = 0;
  p2.right = 5;
  printf("p2.left: %d and p2.right: %d\n", p2.left, p2.right);
}
