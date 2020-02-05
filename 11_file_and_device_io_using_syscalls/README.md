## System Calls
The OS is responsible for management devices, processes, memory and file system.
When using C standard library, underneath the covers, system calls are being used.
For example, when issuing malloc() or calloc(), memory management tasks are performed in memory already allocated.
However, real memory allocation takes place using sbrk() system call which adjusts the break point to increase heap's size.
We're now going to work with file streaming interface where opening and closing files are done using system calls beehind the scene.
## File descriptors
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

### Open()'ing a File Descriptor

int open(const char * path, int oflag, mode_t mode);
There's either 2 or 3 arguments to open()
In the simplest case, when we're not creating a file, open() only takes 2 arguments.
If a file is created, we need to specify the permission mode of that file, such as read/write/exec.

In theory, open() is similar to fopen() in the simplest case when we're just opening a file:

int fd = open("path/file", O_RDONLY);

The oflag is an integer that indicates the desired open condition for the file.
Fortunately, we don't have to use integer so we can use constants instead.
In the above example, the file at given path is openened as read-only with O_RDONLY flag.

If we wanted to open a file for writing, truncate file if it exists or create it if it doesn't, then we need to combine flags and specify a mode.
Here's an example:

int fd = open("file.txt", O_WRONLY | O_TRUNC | O_CREAT, 0664);

The second argument O_WRONGLY | O_TRUNC | O_CREAT is known as ORing and refers to set of options that are combined using bit-wise OR operator.
The way it works is that each option sets a bit in a field, in this case, one bit in the integer.
The bitwise or, will result in the accumulation of all the set bits like this:

> 00000000000000000000000000000001      O_WRONLY
> 00000000000000000000010000000000     O_TRUNC
> 00000000000000000000001000000000     O_CREAT
> --------------------------------- OR
> 00000000000000000000011000000001      O_WRONLY | O_TRUNC | O_CREAT

Follow the relevant option flags for opening a file:
* O_RDONLY open for reading only
* O_WRONLY open for writing only
* O_RDWR open for reading and writing
* O_APPEND append on each write
* O_CREAT create file if it doesn't exist
* O_TRUNC truncate size to 0

The mode portion of arguments (0664) is an octet just like we use for chmod command.
The leading 0 is just an indicator that the following value is in octal, not base 10.
There are also settings shortcuts to reference different mode settings in an ORING:
* S_IRUSR 00400 owner has read permission
* S_IWUSR 00200 owner has write permission
* S_IXUSR 00100 owner has execute permission
* S_IRGRP 00040 group has read permission
* S_IWGRP 00020 group has write permission
* S_IXGRP 00010 group has execute permission
* S_IROTH 00004 others have read permission
* S_IWOTH 00002 others have write permission
* S_IXOTH 00001 others have execute permission

So 0644 is equivalent to the following ORING:

S_IRUSR | S_IWUSER | S_IRGRP | S_IWGRP | S_IROTH

We can see that writing modes in octal is much less complex and involves less typing too
