#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/wait.h>
/*
 *  This is a program that executes another program and waits for that program to finish before it exits.
 *  To understand, where child exactly begins to execute code look at 7_child_fork_start.c
 *  Essentially, child executes ls -l and parent is kept on hold because there's a wait() system call
 *  Once child finishes its execution, parent resumes and prints Parent: finished message.
 */
int main(int argc, char * argv[]) {
  // arguments for ls does 'ls -l /bin'
  char * ls_args[3] = { "ls", "-l", NULL };
  pid_t c_pid, pid;
  int status;
  // after fork, both parent and child will execute the code
  c_pid = fork();
  if (c_pid == 0) {
    //if it's a child
    printf("Child: exeecuting ls\n");
    //execute ls
    execvp(ls_args[0], ls_args);
    //only execute this if exec fails
    perror("execvp failed");
  } else if (c_pid > 0) {
    //if it's a parent
    if ((pid = wait(&status)) < 0) {
        perror("wait");
        _exit(1);
    }
    printf("Parent: finished\n");
  } else {
    perror("fork failed");
    _exit(1);
  }
  return 0; //return success
}

