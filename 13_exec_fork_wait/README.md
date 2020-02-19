## Revising program execution

In previous section, we used execv() but there are variations that might be better suited depending on the context:

### execv(char * path, char * argv[])

Given path to  program and argument array, load and execute program and arguments (remember to add NULL as last argument becuase all argv arrays must be NULL terminated)

### execvp(char * file, char * argv[])

Given a filename (of the program) + argument array, find file in $PATH and execute program.

### execvpe(char * file, char * argv[], char * envp[])

Given a filename )of the program) + argument array + custom PATH environment setting (envp), search the PATH for program and execute program with the arguments.

Primary difference between execv and execvp is that we need to provide full path to binary in execv, while execvp will do the search for us.

Have a look at 1_execv_ls-l.c and 2_execvp_ls-l.c

## A little explanation about argv[] argument to execv and execvp

This array must always be NULL terminated:
```c
char * ls_args[] = { "ls", "-l", NULL) };
```
When we do the above, we're essentially doing this:

                 .-----.
     ls_args ->  |  .--+--> "/bin/ls"
                 |-----|
                 |  .--+--> "-l"
                 |-----|
                 |  .--+--> NULL
                 '-----'
Because argv for exec is the same as main, it's easy to write a program that executes any other progrma you pass as parameter.

Try 3_exec_other.c

```c
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[]) {
  execvp((argv+1)[0], argv+1);
            ^
            |
            we're kind of skipping the program's name (3_exec_other.c)
  perror("execvp failed");
}
```
We're doing some hack here by using pointer manipulation to set up the argv array.
When we execute above program this is the array we've got:

              .-----.
     argv ->  |  .--+--> "./3_exec_other" <-- We don't want to use this, so we use (argv+1)[0] as the starting pointer
              |-----|
              |  .--+--> "ls"
              |-----|
              |  .--+--> "-l"
              |-----|
              |  .--+--> NULL
              '-----'

So after pointer manipulation we get this instead:

                .-----.
                |  .--+--> "./exec_other"
                |-----|
     argv+1 ->  |  .--+--> "ls"
                |-----|
                |  .--+--> "-l"
                |-----|
                |  .--+--> NULL
                '-----'
And this is indeed a valid argv for executing ls and yes, I could've used argv[1] as the first argument instead.

## Creating new Process
For that, we use fork() system call which duplicates the calling process and creates a new one with a new PID.

An exact copy of process, memory and open resources is produced when fork() is called.

With the exception of the kernel and init process, all processes are spawned from another process.

All processes have a unique PID whih is a 2-byte (short int) that is represented by pid_t typedef.

By default, fork() lets parent learn child's PID (because such value is returned by fork) but child doesn't know its own PID or even parents PID.

Even parent doesn't know its own PID and because of that there are 2 system  calls to help:

```c
// retrieve current PID
pid_t getpid(void);

// retrieve parent's  PID
pit_t getppid(void);
```
Check out how to print current PID and PPID on 5_getpid_ppid.c

There's also a wait() system call to put  processes on hold.

It's used by a parent process to wait for the status of a child process to change.

A status change occurs for a number of reasons, e.g. program stopped, continued or terminated.

Here's the syntax:

```c
#include <sys/types.h>
#include <sys/wait.h>

pid_t wait(int *status);
```
Once parent calls wait(), it gets blocked until a child changes its state.

Essentially, it is waiting for child to terminate.

This is known as blocking funtion because it blocks and does not continue until an event is complete.

wait system call returns child process' PID that just terminated (or -1 of process has no children).

It takes an integer pointer as argument which is the memory address it sets the termination status of child process.

To learn about exit status of a program we can use macros from sys/wait.h that checks termination status and return exit status.

Here's man page for 2 of them:

> WIFEXITED(status)
>        returns true if the child terminated normally, that is,
>        by calling exit(3) or _exit(2), or by returning from main().
>
> WEXITSTATUS(status)
>        returns  the  exit  status of the child.  This consists of the least significant
>        8 bits of the status argument that the child specified in a call to exit(3) or _exit(2) or as the
>        argument for a return statement in main().
>        This macro should only be employed if WIFEXITED returned true.

There are other checks of termination status in man page.

Check out 6_get_exitstatus.c

Here's a quick note about where exactly child executes the exact copy of the program from once it's forked.

Consider this code:

```c
int main(int argc, char **argv) {
  int return_value;                                                                            /* 1 */
  printf("Only parent process (pid = %d) prints this because it's before fork()\n",getpid());  /* 2 */
  return_value = fork();                                                                       /* 3 */
  printf("Both parent and child should print this");                                           /* 4 */
  return EXIT_SUCCESS;                                                                         /* 5 */
}
```

> Here's the execution flow:
>
> parent process calls fork() → ...
>                             ↘
> parent process               exec() → 1 → 2 → 3 → 4 → 5
>                                                     ↘
> child process                                         4 → 5

