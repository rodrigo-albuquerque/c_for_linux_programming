#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
/*
 *  As default priority of any process is 0, the output should be 0
 *  However, try nice -n 10 ./1_get_priority and we should see the priority should change to 10
 *  Look at this:
 *  ------------
 *  14_scheduler_and_process_state[master !?] $ nice -n -10 ./1_getpriority
 *  nice: setpriority: Permission denied
 *  Priority: 0
 *  14_scheduler_and_process_state[master !?] $ sudo nice -n -10 ./1_getpriority
 *  Password:
 *  Priority: -10
 *  ------------
 *  Notice that we don't have permission to set higher priority (-10) because this is a privileged operation.
 *  Also notice that nice calls setpriority() system call to change priority and that's what's been denied.
 *  sudo command solved the issue and we successfully set priority to -10.
 */
int main() {
  int prio;
  prio = getpriority(PRIO_PROCESS, 0); // retrieves priority of THIS process
  printf("Priority: %d\n", prio);
  return 0;
}
