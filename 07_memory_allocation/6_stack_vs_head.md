# Intro

Now that you understand the two different memory allocation procedures, let's zoom out and take a larger look at how memory in programs is managed more generally.

Where is the stack? Where is the heap? How do they grow or shrink?

To answer these questions, you first need to think of a program as a memory profile.

All information about a program, including the actual binary code and variables all are within the memory layout of a program.
When executing, the Operating System will manage that memory layout, and a snapshot of that memory and the current execution point basically defines a program.
This allows the operating system to swap in and out programs as needed.
On 64-bit machines, the total available memory addresses are from 0 to 264-1.
For a program, the top and bottom of the address space are what is important.
We can look at the program's memory layout in diagram form:
     2^64-1--->  .----------------------.
High Addresses   |      Enviroment      |
                 |----------------------|
                 |                      |   Functions and variable are declared
                 |         STACK        |   on the stack.
base pointer ->  | - - - - - - - - - - -|
                 |           |          |
                 |           v          |
                 :                      :
                 .                      .   The stack grows down into unused space
                 .         Empty        .   while the heap grows up.
                 .                      .
                 .                      .   (other memory maps do occur here, such
                 .                      .    as dynamic libraries, and different memory
                 :                      :    alloocat)
                 |           ^          |
                 |           |          |
 break point ->  | - - - - - - - - - - -|   Dynamic memory is declared on the heap
                 |          HEAP        |
                 |                      |
                 |----------------------|
                 |          BSS         |   The compiled binary code is down here as
                 |----------------------|   well as static and initialzed data
                 |          Data        |
                 |----------------------|
Low Addresses    |          Text        |
      0 ----->   '----------------------'

At the higher addresses is the stack and at the lower address is the heap.
The two memory allocation regions grow into the middle of the address space, which is unused and unallocated.
In this way, the two allocations will not interfere with each other.
The stack base pointer is the current top of the stack, and as functions are called and returned, it will shift appropriately.
The break point refers to the top of the programs data segment, which contains the heap.
As the heap fills up, requirement more space, the break is set to higher addresses.
You should note that this memory layout is virtual.
From the program's perspective it has access to the entire address range, but in reality, this might not be the case because the program is sharing physical memory with other programs, including the operating system.
How that process works is another discussion.

Memory Mapping and Dynamic Libraries

Between the break point and the base pointer is unallocated memory, but it may not be unused.
This region can be memory mapped, which is the process of loading data directly from files into memory.
As the programmer, you can directly memory map files, but often this is done automatically for you when you read and write files.

Another common use for the middle addresses is the loading of dynamic shared libraries.
When you make a call to a function like printf() or malloc(), the code for those functions exist in shared libraries, the standard C library, to be precise.
Your program must run that code, but the operating system doesn't want to have load more code into memory than needed.
Instead, the O.S. loads shared libraries dynamically, and when it does so, it maps the necessary code into the middle address spaces.
