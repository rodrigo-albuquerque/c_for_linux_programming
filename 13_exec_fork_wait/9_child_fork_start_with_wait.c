#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/*
 * As opposed to 8... the parent will always wait for child to finish its executing first before resuming its own and printing
 * So there's no more risk of child becoming orphan and inheriting ppid of init process (1)
 */

int main(int argc, char **argv) {
  int return_value, status; //status is just to store the return status of wait system call below
  printf("Only parent process (pid = %d) prints this because it's before fork()\n",getpid());
  return_value = fork();
  if (return_value == 0) {
    printf("Hello, child (pid = %d, ppid = %d)here printing this bit\n",getpid(), getppid());
  } else if (return_value > 0) {
    // wait system call here blocks parent process execution until child process exits or a signal is received
    wait(&status);
    printf("Hello, parent process (pid = %d) printing this\n", getpid());
  } else {
    perror("fork failed"); // check out ../12_processes/8_exec_ls.c for perror explanation
    _exit(1);
  }
  return EXIT_SUCCESS; // macro for 0
}

