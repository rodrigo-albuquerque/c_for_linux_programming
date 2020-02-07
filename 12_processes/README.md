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
          |        +--------------+          .  ^   |  ^  |.--------------> +----------------------+
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

### _exit()

Terminates process immediately without any additional code execution

### exit()

Cleanly terminates process by invoking additional code as requested by user and to manage ongoing I/O.

### _Exit()

Terminates process immediately. It's a wrapper to _exit()

![Exit Process LifeCycle Image](https://www.usna.edu/Users/cs/aviv/classes/ic221/s16/lec/13/img/process_lifecycle_exit.png)

## How does a process get created?


