#include <stdio.h>
#include <stdlib.h>
/*
 * Dangling pointer is when a pointer value once referenced allocated memory but such memory has been deallocated.
 *  Once p has been freed, memory referenced by p's value can be reclaimed by other allocations.
 *  If we write to p's address, we might be overwriting memory for some other value and corrupting our program.
 *  Once memory is freed, it should never be dereferenced
 *  Such kind of memory violations can load to SEGFAULT.
 *  Another common mistake is double free.
 *  Heap allocation functions maintain a special data structure so that's easy to find unallocated memory to reallocate for future malloc() calls.
 *  If we use free() twice on a pointer, we corrupt such process and the result can be a core dump or some other scary error.
 */
int main(int argc, char *argv[]) {
  int *p = (int *) malloc(sizeof(int));
  //... code
  free(p);
  //... code
  *p = 10;
  printf("%d\n",*p);
}
