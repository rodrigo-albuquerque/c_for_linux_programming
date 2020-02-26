# What is the scheduler?

It decides which process runs next on the CPU(s).

It ensures that all processes have a reasonable chunk of CPU time in an efficient way.

It has to take into consideration that not all processes are ready to run, e.g. process might be waiting for I/O operation to complete.

# Scheduler design principles

Therefore, a good scheduling algorithm should meet the following constraints:

- CPU usage: fully utilised, i.e. if there's a process that can run, it should be running.
- Turnaround time: how long does it take for process to run once it's ready to run?
- Fairness: all tasks, of equal priority, should have same opportunity to run and no process starved for resources or unable to run.

## FIFO

What if we let process get CPU time based on first-come-first-served strategy?

It passes our fairness principle but it has a terrible turnaround as processes at the end of the queue would potentially end up waiting for a long time to have some CPU time.

Imagine a situation where another process that came in first is taking a long time to run.

## Deadline Scheduling

What if we adopt a strategy of scheduling CPU time to processes based on how long it takes for it to run?

We can't because we don't have this information in advance.

## Preemptive Scheduling

This is when a process gets scheduled for some amount of time, then it's preempted before it gets to finish and another process takes over for some more time which eventually gets preempted to allo a different process to run, and so on.

In this case, a process doesn't have to fully complete its task before another process can run.

We can then come up with a strategy to schedule tasks.

For example, we can let process task run for a set amount of time, say 300 milliseconds and then swap it out and move on to next task for a different process which also runs for 300 milliseconds, and so on.

However, it doesn't take into account a situation whether a job could've finished its task if it ran for more 10 milliseconds.

The other situation is when a running process is waiting for an I/O operation during its 300 milliseconds.

We need to somehow prioritise things.

# Priority Queue Scheduling

In the real world, Linux implements a hybrid strategy that is a mix of round-robin scheduling and priority scheduling.

Processes with higher priority go first and there's a set of priorities ranging from -20 to +19.

Within each priority, each process run in a round robin fashin but which queue it belongs to is chosen  b ased on priority.

Process starvation is also handled by moving lower priority processes that haven't run for a while to higher priority queues.

This strategy is called multi-level queue scheduling and is very effecitive highly efficient.

# Niceness of a program

The nicer the process is (to other processes), the more willing it is for another process to run in its place.

Therefore, nicer processes have lower priority.

However, +19 = nicest (lowest priority), -20 = very mean(highest priority)

Here's how we list niceness of processes on Linux:

```console
# ps axo nice,comm,pid --sort nice | head -30
 NI COMMAND            PID
-20 rcu_gp               3
-20 rcu_par_gp           4
-20 kworker/0:0H-kb      6
-20 mm_percpu_wq         8
-20 kworker/1:0H-kb     19
-20 netns               21
-20 writeback           26
-20 crypto              30
-20 kintegrityd         31
-20 kblockd             32
-20 edac-poller         33
-20 devfreq_wq          34
-20 kthrotld            55
-20 ipv6_addrconf       88
-20 kstrp               98
-20 ata_sff            142
-20 mpt_poll_0         144
-20 scsi_tmf_0         146
-20 scsi_tmf_1         148
-20 mpt/0              149
-20 kworker/0:1H-kb    204
-20 scsi_tmf_2         210
-20 kworker/u257:0-    238
-20 kworker/1:1H-kb    240
-20 ext4-rsv-conver    242
-20 ttm_swap           497
-20 kworker/u257:2-    518
 -1 ulogd             2887
  0 systemd              1
  ```
As we might guess, processes with negative values are vital to Linux.
For example, netns is responsible for handling network namespace execution.

In the middle, we might find user-level processes (priority 0):
```console
# ps axo nice,comm,pid --sort nice | grep 'kthreadd ' -B1 -A 10
  0 systemd              1
  0 kthreadd             2
  0 kworker/u256:0-      7
  0 ksoftirqd/0          9
  0 rcu_sched           10
  0 rcu_bh              11
  - migration/0         12
  0 kworker/0:1-eve     13
  0 cpuhp/0             14
  0 cpuhp/1             15
  - migration/1         16
  0 ksoftirqd/1         17
  ```
At the bottom, we find the ones with lowest priority:
```console
root@kube-master:~# ps axo nice,comm,pid --sort nice | tail -3
  0 tail             12339
  5 ksmd                28
 19 khugepaged          29
 ```
# getpriority() and nice()
In C, we can retrieve current process priority  by using getpriority() system call:
```console
#include <sys/time.h>
#include <sys/resource.h>

int getpriority(int which, int who);
```
which = type of priority, i.e. one of those: PRIO_PROCESS, PRIO_PGRP or PRIO_USER.
who = depends on 'which' type, i.e. for PRIO_PROCESS, who = process ID, for PRIO_PGRP, who = process group ID and for PRIO_USER, who = user ID.

Check 1_get_priority.c

However, we should kep in mind that nice() returns new priority value so if we're checking errors, we must compare the output  of nice() with the value we expect.

# Process States

Scheduler must consider both process' priority AND if it's ready to run.

The latter is where process states come in handy.

Running (R): currently running or ready to run (waiting for CPU to pick it up)
Uninterruptible sleep (D): waiting for an event (usually I/O) to complete, no signal can kill such process in this state, not even SIGKILL. There's nothing you can do. Either wait for process to exit or reboot.
Interruptible sleep (S): just like D, it's also waiting for an event but it responds to signals.
Zombie/Defunct (Z): when parent exits before its child, i.e. programmer didn't add wait() to code to wait for child to exit first
Idle kernel thread (I): an Interruptible sleep for kernel threads (kthreads) processes with the difference that it doesn't contribute to load average. See this: https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/commit/?id=80ed87c8a9ca0cad7ca66cf3bbdfb17559a66dcf
Stopped by job control signal (T): This is when we type Ctrl+Z and send job to background by sending SIGTSTP and control is returned to shell.
Stopped by debugger during tracing (t): name says it all.


