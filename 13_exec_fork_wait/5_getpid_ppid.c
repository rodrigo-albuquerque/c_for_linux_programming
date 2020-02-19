#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/*
 *  If we execute this program, we'll get different PIDs but same PPID.
 *  That's because parent process is the shell itself
 *  Try echo $$ to confirm the PPID matches
 *  Above shell command returns current shell's PID
 */
int main() {
  pid_t pid, ppid;
  // get this process' PID
  pid = getpid();
  // get PPID of this process
  ppid = getppid();

  printf("My pid is: %d\n", pid);
  printf("My ppid is: %d\n", ppid);
  return 0;
}
