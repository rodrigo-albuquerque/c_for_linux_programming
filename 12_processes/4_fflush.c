#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
/*
 *  We don't need to rely on exit procedures to clear I/O buffers.
 *  We can do it ourselves using the fflush() library function.
 */
int main() {
  // IO is buffered because there's no newline
  printf("Will print only once flushed");
  fflush(stdout); // flushing stdout's buffer, printing...
  _exit(0); // immediately exits...
}
