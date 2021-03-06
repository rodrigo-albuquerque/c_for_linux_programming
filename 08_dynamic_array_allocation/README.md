This is what happens when we need to allocate memory on the heap:

                                             STACK           HEAP
                                             .---.----.     .----.
     int * p = (int *) malloc(sizeof(int));  | p |  .-+---->| 10 |
     *p = 10;                                '---'----'     '----'

On the left, we use malloc() to allocate enough memory to store an int, and we assign the address of that memory to the integer pointer, p.
On the right, is the stack diagram of this allocation.
The pointer p exists on the stack, but it now references the memory on the heap.
We now know, in excruciating detail, that arrays and pointers are the same.
This idea extends to the dynamic allocation of arrays.
If we have an integer pointer p it can point to a single integer, or it can point to the start of a sequence of integers.
A sequence of contiguous integers is an array.
All we need is to allocate enough space to store all those integers, and malloc() can do that too.
Consider what's needed to allocate an array of a given size.
For example, how many bytes would be needed to allocate an integer array of size 5?
There are 4-bytes for each integer, and the array holds 5 integers: 20 bytes.
To allocate the array, we just ask malloc() to allocate 20 bytes, and cast the result to an int pointer, like below:

                                                 .---.----.     .----.
      int * p = (int *) malloc(5*sizeof(int));   | p |  .-+---->| 10 | p[0]
      p[0] = 10;                                 '---'----'     |----|
      p[1] = 20;                                 | 20 | p[1]
      .                                          |----|
      .                                          :    :
      .                                          .    .
      p[4] = 50;                                 :    :
                                                 |----|
                                                 | 50 | p[4]
                                                 '----'
The result of the malloc() is 20 bytes of contiguous memory which is referenced by an integer pointer, which is the same as an array!
We can even use the array indexing method, [], to access and assign to the array.

