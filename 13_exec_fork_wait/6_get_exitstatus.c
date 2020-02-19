#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/wait.h>

int main() {
  pid_t c_pid, pid;
  int status;

  c_pid = fork(); //duplicate

  if (c_pid == 0) {
    //child
    pid = getpid(); // notice that getpid() returns the PID of current running process and stores in pid
    printf("Child: %d: I'm the child\n", c_pid);
    printf("Child: sleeping for 2-seconds, then exiting with status 12\n");
    //sleep for 2 secs
    sleep(2);
    //exit with status 12
    exit(12);
  } else if (c_pid > 0) {
    // parent
    // waiting for a child to terminate
    pid = wait(&status); // &statys is where wait() stores its return value
    // WIFEXITED returns true if child terminated normally, i.e. by calling exit(3) or _exit(2), or returning from main()
    if (WIFEXITED(status)) {
      printf("Parent: Child exited with status: %d\n", WEXITSTATUS(status));
    }
  } else {
    //error: The return of fork() is negative
    perror("fork failed");
    _exit(2); //exit failure, hard
  }
  return 0; //success
}
