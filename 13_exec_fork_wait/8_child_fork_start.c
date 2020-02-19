#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int return_value;
  printf("Only parent process (pid = %d) prints this because it's before fork()\n",getpid());
  return_value = fork();
  // child processes executes from here onwards alongside with parent process in parallel
  if (return_value == 0) {
    // because only child has pid = 0 then only child process prints this bit
    printf("Hello, child (pid = %d, ppid = %d)here printing this bit\n",getpid(), getppid());
    // because there's no wait(), parent process may exit before child terminates so child becomes orphan
    // when this happens, we should see parent printing first followed by child
    // and is re-parented (adopted) by init process, so next program 9_child_fork_start_with_wait.c we add wait to correct it
  } else if (return_value > 0) {
    // parent process pid is always > 0 so parent will print this bit
    printf("Hello, parent process (pid = %d) printing this\n", getpid());
  } else {
    // a value < than 0, i.e. anything else, means that fork failed
    perror("fork failed"); // check out ../12_processes/8_exec_ls.c for perror explanation
    _exit(1);
  }
  return EXIT_SUCCESS; // macro for 0
}

