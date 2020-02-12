#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
/*
 *  execvp() looks better eh?
 *  The reason for choosing execv() could be security as $PATH can be changed by an attacker.
 *  Let's say an attacker want your program to run a rogue ls command.
 */
int main(int argc, char * argv[]) {
  // argv array for ls -l
  char * ls_args[] = { "ls", "-l", NULL };
  // let's use just the name ls rather than /bin/ls
  // as it's going to search $PATH variable
  execvp(ls_args[0], ls_args);
  perror("execv");
  return 2;
}
