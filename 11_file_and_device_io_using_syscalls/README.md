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

We can see that writing modes in octal is much less complex and involves less typing too.

## User Masks for File Creation

Umask is a way of setting which permissions of newly created files should be returned off by default.

The umask's value is octal. The bits that are set to one indicate that those permissions should be turned off by default.

By typing umask command we can see what current umask the system is using.

Here's the trick to map umask values to permissions

Keep these numbers in mind:
.----------.----------
|    r     |    4    |
|----------|---------|
|    w     |    2    |
|----------|---------|
|    x     |    1    |
+----------|---------+

Here's the output of umask on my mac: 0022

Assume a default mask of 0666, 0022 would make permissions 0644 (0666-0022=0644).

We just subtract the default mask for whatever value is returned by umask.

Now, 0644 means the following:
    ------> both group and other permission is read (4) only.
    |  |
0 6 4 4
| |--> 4 (r) + 2 (w), so owner permission is rw
\ no special bit set

All that means is that if we create a file, it should have the following permission:

$ touch test
$ ls -lh test
-rw-r--r--  1 albuquerque  1437522721     0B  6 Feb 14:54 test

Special permission value meaning (the first digit, remember?):

1xxx = SUID (Set User ID) makes executable program run with the effective user id (uid) of the owner, i.e. no matter who executes it, the program executes with the owner's permissions.
2xxx = SGID (Set Group ID), runs with effective group id (GID) of owner.
1xxx = sticky bit, that's useful for shared directories where many users may create their own files and we just want each user to be able to delete their own file.

Man page says that stick-bit directory, i.e. a directory created with such flag is a directory where the deletion of files is restricted.
Files in such directory may only be removed or renamed by a user if ALL of the following conditions apply:
- the user has write permission for the directory
- the user is the owner of the file, the owner of the directory, or the super-user.

## close()'ing a File

Just use close() system call defined in unistd.h:

int close (int filde)

All open file descriptors should be closed whenever they're no longer needed.
Once program exits, file descriptors are closed automatically.

## Appendix - How umask calculation is done under the hood

It's like this:

> mode & ~umask

& = AND
~ = NOT

AND operator checks (and returns true only) if both values are true
The NOT operator inverts all bits, i.e. if 1 it becomes 0 and vice-versa.

So if we create a file with permission 0644 and mask 0022, we get the final permission like this:

  0664 & ~(0022)
= 0644 &   0755
= 0644

The inverse of 0022 in binary is:

~  000 -> 111 = 7 = 7-0
~  010 -> 101 = 5 =  7-2
~  111 -> 101 = 5 = 7-2

Inverse flips all the bits so it's the same as subtracting the value from 7. With inverse complete, we can now do the bitwise AND of 0755 and 0644 like this:

  101 101 000
& 111 100 100
--------------
  110 100 100 = 644

The mask ensures we never create a file with more permissions than we want.
