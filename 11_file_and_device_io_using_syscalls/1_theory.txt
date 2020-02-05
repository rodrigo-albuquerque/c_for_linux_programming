OS is responsible for management devices, processes, memory and file system.
When using C standard library, underneath the covers, system calls are being used
For example, when issuing malloc() or calloc(), memory management tasks are performed in memory already allocated.
However, real memory allocation takes place using sbrk() system call which adjusts the break point to increase heap's size.
We're now going to work with file streaming interface where opeeining and closing files are done using system calls beehind the scene.

