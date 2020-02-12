#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
/*
 *  With execv() we need to provide full path of the program
 */
int main(int argc, char * argv[]) {
  // argv array for: /bin/ls -l
  char * ls_args[] = { "/bin/ls", "-l", NULL };
  //                                  ^
  //       all argv arrays must be ___|
  //       NULL terminated

  // execute program
  execv(ls_args[0], ls_args);
  //     ^               ^
  //     |               |
  // Name of program     argv array
  // is ls_args[0]       for ls_args


  //only get here on error
  perror("execv failed");
  return 2;
}
