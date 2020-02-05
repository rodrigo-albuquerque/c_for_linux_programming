#include <stdio.h>
#include <stdlib.h>

/*
 *  Because allocating items as an array is so common, we have a special function for it:
 *  int *p = (int *) calloc(5, sizeof(int));
 *  While allocating arrays with malloc() is simple and effective, it can be problematic.
 *  First off, malloc() makes no guarantee that memory allocated will be clean — it can be anything.
 *  For example, consider this simple program:
 */

int main(int argc, char *argv[]) {
  int *a = (int *) malloc(20 * sizeof(int));
  int i;
  for (i = 0; i < 20; i++) {
    printf("%d\n",a[i]);
  }
}
/*
 * What is the output of this program?
 * We don't know. It's undefined.
 * The allocated memory from malloc() can have any value, usually whatever value the memory used to have if it was previously allocated.
 * If you don't believe me, try running and executing the program a few times, and you'll see that you can get widely different results.
 * This just proves that memory allocated by malloc() may not be clean!
 */
