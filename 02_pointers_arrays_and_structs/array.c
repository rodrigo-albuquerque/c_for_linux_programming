#include <stdio.h>

int main (int argc, char * argv[]) {
  int array[10];
  int i;
  //assign to the array
  for (i=0; i<10; i++) {
    array[i] = 2*i; //index times 2
  }
  // references the array
  for (i=0; i<10; i++) {
    printf("%d:%d:\n",i,array[i]);
  }
}
