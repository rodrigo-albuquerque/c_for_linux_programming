#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 *  This is the first lesson!
 *  Both arrays have same length but they've got different sizes
       <------------------------ 24 bytes ---------------------------->
       .---------------.----------------.--- - - - ---.----------------.
a   -> |             0 |              1 |     ...     |              7 |
       '---------------'----------------'--- - - - ---'----------------'

       .---.---.---.---.---..---.---.
str -> | H | e | l | l | o | ! | \0 |
       '---'---'---'---'---'---|----'
'
       <-------  7 bytes ------>
 * Next: pointer_math.c
 */
int main(int argc, char * argv[]) {
  int a[] = {0,1,2,3,4,5};
  char str[] = "Hello!";
printf("sizeof(a):%d, length(a):%d\nsizeof(str):%d, length(str):%d\n",
      (int) sizeof(a),
      (int) sizeof(a)/(int) sizeof(int),
      (int) sizeof(str),
      (int) strlen(str)
      );
}

