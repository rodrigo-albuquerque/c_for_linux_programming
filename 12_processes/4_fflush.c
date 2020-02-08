#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
/*
 *  Reason why stderr is unbuffered by default is because we want errors to be reported immediately, not when it's convenient buffer-wise.
 *  The side effect is that writes to stderr are more expensive since they require an immediate context switch.
 *  We can change the policy for how an I/O stream is buffered and that's what we'll look into 5_exit_setvbuf.c
 */
int main() {
  // by default, I/O is not buffered for stderr
  fprintf(stderr, "Will print because stderr is unbuffered by default");
  _exit(0); // immediate exit!
}
