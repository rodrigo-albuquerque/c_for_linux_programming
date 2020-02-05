#include <stdio.h>
#include <stdlib.h>

/*
 * A string in C is just an array of characters.
 * So an array of strings is a double array of characters.
 * We know how to declare strings like this:
 * char str1[] = "This is a string";
 * However, we know that pointers and arrays are the same so we can also declare a string like this too:
 * char * str2 = "This is also a string";
 * The difference between above 2 declarations is in how and where C actually stores the string in memory.
 */

int main(int argc, char *argv[]) {
  char str1[] = "This is a string";
  char *str2 = "This is also a string";

  printf("str1: %s \t\t &str1:%p\n", str1,str1);
  printf("str2: %s \t &str2:%p\n",str2,str2);
}
/*
 * Both print fine as strings but str1 is located in stack memory region and str2 in data segment.
 * Takeaway here is that we can now refer to strings as char * types
 */
