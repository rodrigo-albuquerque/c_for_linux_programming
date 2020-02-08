#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
/*
 *  This functio doesn't print because I/O buffer holds the string but _exit() exists without flushing the buffer
 */
int main() {
  // No new line, so I/O buffered
  printf("Does not print");
  _exit(0); //immediate exit!
}
