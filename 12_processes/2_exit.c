#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
/*
 *  exit() flushes all buffered writes before calling _exit()
 */
int main() {
  // No new line, so I/O buffered
  printf("Will print");
  exit(0); // C standard exit
}
