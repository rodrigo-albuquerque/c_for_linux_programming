/*helloworld.c*/
/* argc refers to number of command line arguments  passed in, which includes the  actual name of the program,
 * as invoked by the user.
 *
 * argv contains the actual arguments, starting with index  1.
 *
 * So, if you ran your program like this:
 * ./program hello world
 * Then:
 * - argc would be 3.
 * - argv[0] would be "./program"
 * - argv[1] would be "hello"
 * - argv[2] would be "world".
 */
#include <stdio.h>

// Hello World in C
int main(int argc, char * argv[]) {
  printf("Hello World\n");
}
