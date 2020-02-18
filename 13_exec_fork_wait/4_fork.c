#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/*
 *  fork() system call returns twice, one in parent and once in child and it returns different values in each.
 *  Reason is because once fork() is called, OS creates a completely new process which is an exact copy of original process.
 *  pid_t is an abstraction of int to allow different platforms to use the same type (pid_t) and still be compatible.
 *  For example, 32-bit vs 64-bit might use int of different sizes.
 *  In reality, it's implemented as a typedef.
 *  In below code, the parent's return value = child's PID and child has to return 0 (success) or -1 (if there's an error and _exit() because something wrong happened).
 *
 */
int main() {
  pid_t c_pid;

  c_pid = fork(); // duplicate
  if ( c_pid == 0 ) {
    //child: The return of fork() is zero
    printf("Child: I'm the child: %d\n", c_pid);
  } else if (c_pid > 0) {
    //parent: The return of fork() is the PID of the child
    printf("Parent: I'm the parent: %d\n", c_pid);
  } else {
    //error: The return of fork() is negative
    perror("fork failed");
    _exit(2); // hard exit upon failure
  }
  return 0; //success
}
