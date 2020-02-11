--------------------
The OS as a Resource
--------------------
OS' main function is to manage system resources:
1. Device Management: hardware devices
2. Process Management: invocation and execution of program, a process, managed by OS, including its state (running, stopped, etc) as well as loading code.
3. Memory Management: access to physical/virtual memory is controlled by OS, i.e. process memory layout and current allocations.
4. File System Management: OS is responsible to ensure programs can read/write from/to filesystem without corrupting it and only access permitted files.

--------------------
Kernel vs User space
--------------------
Kernel of OS is trusted to perform all protected system resource actions. We say such actions are executed in Kernel space.
Actions that can be performed without privilege, such as adding 2 numbers, reading through an array or reading/writing data already allocated in memory, are executed in user space.
i.e. no kernel intervention is required for such tasks to be completed.

-------------
System Calls
-------------
When privileged access is required, a context-switch between user process and kernel takes place.
A context switch occurs when process execution is stopped, current state is saved and offloaded from CPU, and kernel is swapped in to complete the protected task.
Once task is completed, kernel returns the desired results to user process and is swapped out.
The process is then swapped back in and execution continues from that point on.
A system call is the intermediate, entry point or API for requesting privileged actions to kernel.
System calls are defined in Unix Standard Library (unistd.h).

-----------------
Memory Allocation
-----------------
                           .________________.
                           |   environment  |
                           | -------------- |
                           |      stack     |
                           |                |
     sbrk() moves          |                |
     break point to        |                |
     allocate more         |                |
     memory                |                |
                           |                |
                           |                |
        break point -----> | -------------- |
                      ^    | new allocation | malloc() manages how
                      |    |                | new allocations are
                      |    |                | used by the programmer
                      |    |                |
        break point -----> | -------------- |
                           |      heap      |
                           |----------------|
                           |     data/bss   |
                           .________________.

C memory allocation routine is about managing memory that has already been allocated.
As processes free and allocate new memory all the time, malloc() attempts to find contiguous memory blocks to fulfill those requests.
There are a couple of ways of doing it. For example, malloc() can find first region of unallocated space that fits the block even if it's too big.
This is called First Fit.
The other example would be to find the region of unallocated memory that is as close to requested size.
This is called Best Fit.
Both strategies are fine but the kernel is not involved in this process.
However, when there's no more space in the heap, the break point needs to be adjusted so kernel has to get involved.
A system call sbrk() is called to adjust break point, effectively allocating more memory.

-------------
Kernel Traps
-------------
Invocation of kernel to perform a context-swich is done via a trap.
Trap is a special instruction to CPU that a task in kernel mode has to be performed.
CPU interrupts current process, saves state and invokes kernel with trap information.
To allocate more memory, the trap is done by sbrk() system call which invokes the kernel function sys_sbrk().


     =====================> USER SPACE <===================== | ===========> KERNEL SPACE <===========
     .--------------------.         .--------------------.    |     .-----------------------.
     | malloc() {         |    .--->| sbrk() {           |    |.--->| sys_sbrk() {          |
     | //C library        |  ./     |  //Unix Library    |   ./     |  //System Call        |
     |   sbrk() ------------/       |  trap sys_sbrk(); ----/ |     |  //adjust break point |
     | }                  |         |  return;           |    |     |                       |
     |---------------------         ---------------------|    |     |  return;              |
     |     stdlib.h       |         |     unistd.h       |    |     | }                     |
     .--------------------.         |--------------------|    |     |-----------------------|
                                                         |

----------------------------------------
Recognising System Calls using Man Pages
----------------------------------------
Sections:
(1) General commands, such as those found in bash environment
(2) System calls, such as sbrk()
(3) Library functions, such as malloc()
(8) System Administration

For example, typing man malloc, we see it is in section 3 as per MALLOC(3) header and that it's part of C standard library via include statement.

```c
MALLOC(3)           Linux Programmer's Manual                    MALLOC(3)

NAME       malloc, free, calloc, realloc - Allocate and free dynamic memory

SYNOPSIS
       #include <stdlib.h>

       void *malloc(size_t size);
       void free(void *ptr);
```

If we look at sbrk() command by typing man sbrk it should show section 2 and include statement should show unistd.h instead.

If we type man read, we should be taken to bash built-in function read() instead of system call read().

Reason is because read() for bash is in general command in section 1 of manual and preference for man command is always to retrieve lowere numbered pages.

To go to read() system call we need to type in man 2 read instead.
