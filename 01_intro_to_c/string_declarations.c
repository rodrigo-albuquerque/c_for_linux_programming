#include <stdio.h>
#include <stdlib.h>

/*
 * char = 1 byte, so sizeof matches expectations
 * When we use %s format it looks for \0 (NULL) terminated marker to determine string's length
 * Because "a" is NOT NULL terminated, printf() function  is unable to determine where string ends
 * That's why  it prints extra  characters not part of the string.
 * We can change that declaration to somethingl ike  this:
 *  char a[]   = {'G','o',' ','N','a','v','y','!', '\0'};
 *  But this  is really annoying way to do string declarations, so check out string_declarations2.c
 */

int main(int argc, char * argv[]) {
  char a[] = {'G','o',' ','N','a','v','y','!'};
  char b[10] = {'G','o',' ','N','a','v','y','!'};
  int i;

  printf("sizeof(a):%d sizeof(b):%d\n",
      (int) sizeof(a),
      (int) sizeof(b)
      );

  printf("\n");
  for(i=0;i<8;i++) {
    //print char and ASCII value
    printf("a[%d]: %c (%d)\n",i,a[i],a[i]);
  }

  printf("\n");
  for(i=0;i<10;i++) {
    //print char and ASCII value
    printf("a[%d]: %c (%d)\n",i,b[i],b[i]);
  }

  printf("\n");
  printf("a: %s\n",a); // format print the string
  printf("b: %s\n",b); // format print the string

}




