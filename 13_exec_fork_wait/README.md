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


