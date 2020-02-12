## Definition

Program is set of instructions for how a process operates when it runs.
A process is an executing instance of such a program.
There can be multiple instances of the same program running.
E.g. when multiple users are logged in at the same time,e ach running a shell, which is the same program with multiple executing instances.
A process can also be though of as an OS abstraction containing multiple programs as individual units.
It is through such abstraction that OS can provide isolation by ensuring that one process cannot interfere with another.
A process is also the core unit of the OS resource of Process Management where the main goal is to determine which process has access to the CPU and at what time.

                   +--------------+                                         +---------------+
                   | user/library |-                              .-------->|      Exit     |
          |<-------| functions    | \. exit                call ./  .-------|     Handler   |
          |        +-------------+    \.                      ./  ./ return +---------------+
          |       call ^ | return       \-->  +-----------+--/  ./
    _exit |        +---|-∨--------+ exit      | exit      | <--/
          |        |     main     |-------->  | function  |
          | <------|   function   |           +-----------+      call
          |        +--------------+             ^   |  ^  |.--------------> +----------------------+
          |            ^ | return          .----|   |  |.                   | Standard I/O CleanUp |
          |       call | ∨               ./         |    \.-----------------+----------------------+
          |        +---------------+   ./ exit      |             return
          |        |   C start-up  |-./             |
          |        |    routines   |                |
          |        +---------------+                | _exit
          |                ^                        |
          |                |  exec                  ∨
          --------------------------------------------------------------------------------------------
          |                                        Kernel                                            |
          --------------------------------------------------------------------------------------------
## How does a process die?

There are a couple of ways of achieving this. One would be to dereference NULL and force a SEGFAULT.
However, the standard way of doing it is to allow the main() function to return.
Question is: what do we do if we want our program to termine from another part of the program other than main()?
We need a separate way  to do that and the solution is exit call.

\_exit()
------

Terminates process immediately without any additional code execution

exit()
------

Cleanly terminates process by invoking additional code as requested by user and to manage ongoing I/O.

\_Exit()
------

Terminates process immediately. It's a wrapper to _exit()

![Exit Process LifeCycle Image](https://www.usna.edu/Users/cs/aviv/classes/ic221/s16/lec/13/img/process_lifecycle_exit.png)

The green arrows show _exit() system call that leads to the  direct termination of the process.
Once process is terminated, kernel (scheduler more specifically) to choose which process should run next, which is why flow points towards kernel.
However, a call to exit() (no underscore), at  any point in program excecution, starts a separate set of actions.
These include running exit handleres and I/O procedures as seen in red diagram.
Eventually, once exit procedures complete, exit() calls _exit() to do the final termination.
Not picture in the diagram is _Exit(),  which has the same action as _exit().
It's worth pointing out that exit procedure has both a system call version and a library call version.
In general, when we program, we only use the library functions.

### I/O buffering and Exit Procedures

C standard library does buffering to limit the number of system calls, e.g. calls to write() as they're costly.
System calls requires entire process to be paused, saved and swapped out in favour of Kernel, which then performs an action on behalf of user.
Once action is complete, user process is swapped back in to complete its operation.
So buffering is one way to avoid excessive calls.

An example is a printf(). Printing doesn't occur immediately. Instead, it is buffered.
A print is only unbuffered whenever the buffer is full or when a line completes (with \n - the newline symbol).

Consider this program:

```c
int main() {
  printf("Hello World!\n");
}
```
Because of new line, buffer is flushed and "Hello World" is printed to terminal.

Now, consider this other one:

```c
int main() {
  printf("Hello World!");
}
```

There's no new line but when main() function returns it calls exit() and exit() performs the standard I/O clean up, flushing all buffered writes.

When main() function returns, it returns to another function within C startup routetine which then calls exit().

However, when we call _exit(), buffers are NOT cleared and process exits straightaway.

Have a look at 2_exit.c, 3_underscore_exit.c and 4_fflush.c

### Exit Status

Every program exits with some status which can be checked to learn information about the execution of a process.

We can set exit status of a program via various exit() calls:

```c
_exit(int status);
exit(int status);
_Exit(int status);
```
Additionally, main()'s return value implicitly sets the exit status which can be one of the following:
0: success
1: failure
2: error

## How does a process get created?

When we execute a program, main() is not really the first thing that gets started behind the scenes.
There are start-up routines that are executed first to set up our environment.
Only once those complete, main() is called.
Also, when main() returns it reeturnws to those start-up routines which eventually call exit().
The way a program loads and executes as a process is through the exec family system call, more specificallt execv() and execvp().

![The birth of a Process](https://www.usna.edu/Users/cs/aviv/classes/ic221/s16/lec/13/img/process_lifecycle_exit_exec.png)

So how does a program load and execute as a process?

Check out 1_exec_ls.c

Executing a new program is different to creating a new one.
Processes are created by dyplicating another process by using fork() system call.
Such system call creates an exact copy of the process from which it is called from so we end up with a parent and a child process executing in parallel.
In child process, after fork, it calls exec() which replaces code inherited from parent with a program and that's it.

Process creation is covered in 13...
