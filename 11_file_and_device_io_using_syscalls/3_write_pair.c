#include <unistd.h>
/*
 *  System calls read() and write() aren't string based I/O, so they read and write any data type.
 *
 * ssize_t write(int fd, const void *buf, size_t count);
 *                  ^               ^            ^
 * file descriptor---'       buffer--'            '-- num. bytes to write
 *
 *  Notice that second argument is not char * (it's void *), which means it accepts pointer to any type.
 *  Therefore, we can call it a buffer.
 *  A buffer is just the general term for an array of bytes with no specific type.
 *  Strings are also array of bytes (as char's) that are NULL terminated.
 *  Pointers can be cast from any data type to byte array (buffer), and work with the data byte-by-byte.
 *  In the example below, we write a pair_t to terminal.
 *  In reality nothing shows up in the terminal. It doesn't print "10" or "20".
 *  Reason is because write() writes raw bytes and the data pair_t is not ascii so the individual bytes will not render like ascii characters.
 *  The terminal doesn't know how to render arbitrary bytes that are not unicode or ascii and as a result, nothing gets displayed.
 *  However, the bytes are definitely written and we can see them by read()'ing those bytes in the next program.
 *
 */
typedef struct {
  int left;
  int right;
} pair_t;

int  main(int argc, char * argv[]) {
  pair_t p;
  p.left = 10;
  p.right = 20;
  write(1, &p, sizeof(pair_t));
  return 0;
}
