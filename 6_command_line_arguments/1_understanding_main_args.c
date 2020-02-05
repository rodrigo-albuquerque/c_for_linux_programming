#include <stdio.h>
#include <stdlib.h>
/*
 *
 *  argument ____.             ._____ argument
 *   count       |             |       variables
 *               v             v
 *  int main(int argc, char * argv[]);
 *  Highlights:
 *  Name of program run is always arg[0] which means all programs have at least one argument
 *  Name of program is NOT compiled into the executable.
 *  It is instead passed as true command line argument by the shell, which forks and executes the program.
 *  To confirm this you can just cp the executable to another one with another name and argv[0] should change
 */
int main(int argc, char *argv[]) {
  int i;

  for (i=0; i< argc; i++) {
    printf("argv[%d] = %s\n", i, argv[i]);
  }
}
