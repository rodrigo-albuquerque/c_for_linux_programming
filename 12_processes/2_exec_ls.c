#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/*
 *  Same execv() test but now we added arguments.
 *  Notice that regardless of the number of arguments we add, we need to add NULL as last argument.
 *  This is a requirement described in the manual page of execv().
 */

int main(int argc, char *argv[]) {
  // arguments for "ls -l /var"
  char * ls_args[4] = { "/bin/ls", "-l", "/var/", NULL };
  //             ^                   ^      ^
  //             '                   |      |
  //     Now with an argument to ls -'------'

  // execute ls
  execv(ls_args[0], ls_args);
  //      ^            ^
  //      '            |
  //  path only     whole array, path
  perror("execv failed");
  return 2; // return error status
}
