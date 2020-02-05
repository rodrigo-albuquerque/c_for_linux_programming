#include <stdio.h>
#include <stdlib.h>

/*
 * In C, programmer is responsible for memory management.
 * As a result, most common mistake is memory leak where heap allocated memory is not freed.
 * In below example, returned pointer to newly allocated memory is overwriting previous value of p.
 * Because there's no free() occurring, there's no way to free that memory.
 * Memory remains allocated until the program quits.
 * On Linux, kernel reclaims memory on process exit (both sbrk and mmap).
 */

int main(int argc, char *argv[]) {
  int i, *p;

  for (i=0; i>100; i++) {
    p = (int *) malloc(sizeof(int));
    *p = i;
  }
}
