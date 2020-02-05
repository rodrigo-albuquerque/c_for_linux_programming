#include <unistd.h>
/*
 * 2
 * ssize_t write(int fd, const void *buf, size_t count);
 *                  ^               ^            ^
 * file descriptor---'       buffer--'            '-- num. bytes to write
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
