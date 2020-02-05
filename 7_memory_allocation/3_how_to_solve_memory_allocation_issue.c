#include <stdio.h>
#include <stdlib.h>

/*
 *  We can write functions that return memory references by using global memory's allocation procedure.
 *  This way, memory is not deallocated automatically when function returns and remains within scope for  entirety of program's execution.
 *  In C++ this is the way we allocate global variable:
 *  Node * node = new Node();
 *  Variable node is declared on the stack and has enough memory to store a memory's address.
 *  Value of such memory address is set by the return of the call new Node().
 *  However, above's memory address can't have been allocated on the stack because  we know memory is automatically deallocated when function returns from stack.
 *  Instead, new function performs a dynamic memory allocation in global memory that is NOT associated with the scope of cuntions or stack.
 *  It is allocated to a place called heap, which is the global memory region for programs.
 *  Whenever a program needs to allocate memory globally or in dynamic way, such memory is allocated on the heap, which is shared across the entire program irrespective of function calls.
 *  In C, the 'new' function is called malloc() which takes the number of bytes to be allocated as its argument and returns a pointer to a memory region on the heap.
 *  Here's how to do it:
 *                             .--- Allocate sizeof(int) number of bytes
 *                             v
 * int * p = (int *) malloc(sizeof(int));
 *              ^
 *              '-- Cast to a integer pointer
 *  First, to allocate an integer on the heap, we need to know how big an internet is, i.e. what size it is, which we learn via sizeof() macro.
 *  Since int = 4 bytes, malloc() allocates 4 bytes of memory on the heap and malloc() returns memmory address which is assigned to p.
 *  Since malloc() is general purpose allocation tool, weneed to cast resulting pointer value to int *.
 *  If we don't program won't fail but we would get a compiler warning.
 *  Because it's global variable, we need to explicitly deallocate it, unlike stack-based memory allocations which are implicitly deallocated when function returns.
 *  C doesn't track references like  Python so we need to manually deallocate memory by freeing it  using  free() function which takes a pointer as input and frees the referenceed memory on the heap.
 *  int * p = (int *) malloc(sizeof(int));
 *  ..do something with p..
 *  free(p);
 *  Let's now fix our previous program!
 */

int *plus (int a, int b) {
  int *p = (int *) malloc(sizeof(int)); // allocate enough space for an int
  *p = a + b;
  return p; // return pointer
}

int main(int argc, char *argv[]) {
  int *p = plus(1,2); // p now references memory on the heap
  printf("%d\n",*p);
  free(p); // free allocated memory
}

