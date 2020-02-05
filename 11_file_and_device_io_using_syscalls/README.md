---------------
## System Calls
---------------
The OS is responsible for management devices, processes, memory and file system.
When using C standard library, underneath the covers, system calls are being used
For example, when issuing malloc() or calloc(), memory management tasks are performed in memory already allocated.
However, real memory allocation takes place using sbrk() system call which adjusts the break point to increase heap's size.
We're now going to work with file streaming interface where opening and closing files are done using system calls beehind the scene.
-----------------
File descriptors
---------------
open() and close() system calls are for opening and closing files.
These syscalls do not operate over file streams (FILE *).
Instead, they return an integer value which is called a file descriptor.
All open files in the OS are represented by file descriptors which are indexes into the file descriptor table.
The file descriptor table is a kernel data structure that tracks open files for all programs.
The key concept to grasp is that open files are referenced via an integer value called file descriptor.
Every program comes with 3 standard file descriptors:
- 0: stdin
- 1: stdout
- 3: stderr

When we open a file, it's assigned the next lowest file descriptor number available, which might be 3 for first file, 4 for second file, and so on.
