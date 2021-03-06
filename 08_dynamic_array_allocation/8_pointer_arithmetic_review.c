#include <stdio.h>
#include <stdlib.h>

/*
 *
 STACK (1)         |        STACK  (2)
      .----.----.       |       .----.----.
      | a  |  .-+--.    |       | a  |  .-+--.
      |----|----|  |    |       |----|----|  |
a[0]  |    | 10 |<-.    | a[0]  |    | 5  |<-.
      |    |    |<-.    |       |    |    |<-.
      |----|----|  |    |       |----|----|  |
a[1]  |    | 20 |  |    | a[1]  |    | 20 |  |
      |----|----|  |    |       |----|----|  |
      :    :    :  |    |       :    :    :  |
      .    .    .  |    |       .    .    .  |
      :    :    :  |    |       :    :    :  |
      |----|----|  |    |       |----|----|  |
a[4]  |    | 50 |  |    | a[4]  |    | 50 |  |
      |----|----|  |    |       |----|----|  |
      | p  |  .-+--'    |       | p  |  .-+--'
      '----'----'       |       '----'----'
 *
 *
 */

int main(int argc, char *argv[]) {
  int a[5] = { 10,20,30,40,50 };
  int *p = a; // (1)
  p[0] = 5; // (2)
  printf("%d\n", a[0]); // prints 5 !!
  printf("p: %p  p+1: %p \n", p, p+1); // 4 bytes apart
}
