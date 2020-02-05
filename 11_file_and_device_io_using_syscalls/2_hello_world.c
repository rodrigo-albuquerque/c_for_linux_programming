#include <unistd.h>
/*
 * How do we write a hello world without stdlib.h and stdio.h?
 * We need to user a lower level function, a system call, to write directly to stdout, i.e. terminal window.
 * The system call that writes to a file or device is write().
 * This program is a system call hello world.
 * We first assign the "Hello World" string to the char array hello.
 * We then iterate over the array one character at a time using pointer arithmetic until the end.
 * The output is  via the write() system call, but specifics need further explanation.
 * The foor loop has the following structure:
 * for (init; condition; interation {
 *   // run until condition is false performing iteration on each loop.
 * }
 * So *p (which is a char *) can only evaluate to true or false.
 * It evaluates to true for any character except for 0 or /0 which is when it evaluates to false.
 * Remember that strings are zero-terminated?
 * In that case, when we reach the end of the string the loop evaluates to false (*p = \0) and terminates.
 * Both read() and write() operate over file descriptors rather than file streams, so they read/write from/to buffers, not strings.
 * A file descriptor is just an integer, a number, that refers to a  currently open file.
 * Linux uses filedescriptor number as an indexintofield escriptort able of currentlopen files to gain access to actual device I/O operations should be performed.
 * For e xample, a file on disk, or writing to terminal or reading data from network controller.
 * Follow standard descriptor numbers:
 * Standard Input (0): STDIN_FILENO
 * Standard Output (1): STDOUT_FILENO
 * Standard Error (2): STDERR_FILENO
 * unistd.h provides three constants to standard file descirptors, STDIN_FILENO, STDOUT_FILENO and STDERR_FILENO to improve code's readability.
 */
int main(int argc, char * argv[]) {
  char hello[] = "Hello World\n";
  char *p;

  for (p = hello; *p; p++) {
    //    .-- Write to standard out, file descriptor 1
    //    v
    write(1, p, 1);
    //       ^  ^
    //       |  '--- Number of bytes to write, just the char p points to
    //       |
    //       '-------- char *, points to the byte we want to write
  }
}


