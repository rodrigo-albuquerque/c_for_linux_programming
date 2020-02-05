#include <stdio.h>
#include <stdlib.h>

/*
 *  We can also use [] to walk through the array with our array pointer
 *  p[5] = *(p+5) = array[5]
 *  What [] does is to increment pointer by index and then dereference it:
 *
.-------+------.
| array |   .--+--.
|-------+------|  |
|       |    0 |<-'<-.
|-------+------|     |
|       |    2 |     |
|-------+------|     |
|       |    4 |     |
|-------+------|     |
|       |    6 |     |
|-------+------|     |
|       |    8 |     |
|-------+------|     |
|       | 2017 |<----+----- p+5, array+5
|-------+------|     |
|       |   12 |     |
|-------+------|     |
|       |   14 |     |
|-------+------|     |
|       |   16 |     |
|-------+------|     |
|       |   18 |     |
|-------+------|     |
| p     |   .--+-----'
'-------+------'
 * This is called pointer arighmetic.
 */

int main (int argc, char *argv[]) {
  int array[10];
  int i;
  int *p = array; // p points to array
  // assign to array
  for (i=0; i<10; i++) {
    array[i] = 2*i; // index times 2
  }
  //dereference p and assign 2017
  p[5] = 2017;
  //print array
  for (i=0; i<10; i++) {
    printf("%d:%d\n",i, array[i]);
  }
}
