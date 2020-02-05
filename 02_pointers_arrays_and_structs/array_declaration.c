#include  <stdio.h>
#include <stdlib.h>
/*
 * a[] =  {1,2,3} works out the size by going through the declared values, i.e. implicit declaration
 * b[10] = {1,2,3} size is 10 * 4 = 40 bytes, i.e. explicit declaration
 */
int main(int argc, char * argv[]) {
  int a[] = {1,2,3};
  int b[10] = {1,2,3};
  int i;

  printf("size(a):%d sizeof(b):%d\n",
      (int) sizeof(a),
      (int) sizeof(b)
      );

  printf("\n");
  for(i=0;i<3;i++) {
    printf("a[%d]: %d\n",i,a[i]);
  }

  printf("\n");
  for(i=0;i<10;i++) {
    printf("b[%d]: %d\n",i,b[i]);
  }
}
