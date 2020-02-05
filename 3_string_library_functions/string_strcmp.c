#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 *
      "The  strcmp()  function  compares  the two strings s1 and s2.  It returns an integer less than,
       equal to, or greater than zero if s1 is found, respectively, to be less than, to match,  or  be
       greater than s2.
"
 *  strcmp(str1, str2) returns the following:
 *  -1 if str1 < str2
 *  0 if str1 = str2
 *  1 if str1 > str2
 *  Next: string_length.c
 */
int main(int argc,char *argv[]){

  char str[20];

  printf("Enter 'Navy' for a secret message:\n");

  scanf("%s",str);

  if( strcmp(str,"Navy") == 0 ) {
    printf("Go Navy! Beat Army!\n");
  }else{
    printf("No secret for you.\n");
  }

}
