#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/*
 *  By default, stdin/stdout are line buffered, i.e. input/output is buffered until a newline is read/written.
 *  stderr is unbuffered as errors are supposed to be displayed immediately.
 *  There is also a third choice: fully buffered, i.e. reads/writes occur only once the buffer is full.
 *  The library call to change buffering policy is setvbuf(), which has the following declaration:
 *  int setvbuf(FILE *stream, char *buf, int mode, size_t size);
 *  stream = stdin, stderr, stdout
 *  *buf = buffer memory
 *  size = memory's buffer size
 *  mode can be one of the following:
 *  _IONBF (unbuffered): data is written immediately to device via write() system call.
 *  _IOLBF (line buffered): data is written to device using write() once a newline is found or buffer is full
 *  _IOFBF (fully buffered): data is only written to device using write() once the buffer is full
 *  In general, we'd only change the mode, e.g. when we want stderr to be line buffered.
 *  This is the same as 5_io_exit_stderr.c but because we changed buffer policy to line buffer, it will no longer be printed.
 */

int main() {
  // stderr is now line buffered
  setvbuf(stderr, NULL, _IOLBF, 0);

  // i/o is now buffered for stderr
  fprintf(stderr, "Will NOT print because stderr is now line buffered");
  _exit(0); // exists immediately
}
