#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
/*
 *  In this program, we're using execv() system call to run ls command locally with no arguments.
 *  This is the syntax:
 *  int execv(const char *path, char *const argv[]);
 *                         ^                   ^
 *                         |                   |
 *                         |                   ------ list of arguments (e.g. "-l" "/home/rodrigo") but last argument has to be NULL.
 *                program's path (e.g. "/bin/ls")
 *  Here we created an array with program's name (ls_args[0]) and the list of arguments.
 *  Because there are no arguments, we just add NULL.
 *  Notice that NULL is a requiment as described by "man execve" manual page.
 *  Next program 2_exec_ls.c we execute ls with arguments.
 *  Also note that execv() doesn't return.
 *  Instead, our program is replaced by the program that is being executed and when such program returns then that's the final return.
 *  We also don't need an if statement to check when execv() fails.
 */

int main(int argc, char *argv[]) {
  // execv() takes path to program (/bin/ls) + NULL)
  char * ls_args[2] = { "/bin/ls", NULL };
  // execute ls
  execv(ls_args[0], ls_args);
  // perror function prints our custom message below (execv failed) + the error message corresponding to the return value below .
  perror("execv failed");
  return 2; // return error status
}
