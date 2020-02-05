#include <unistd.h>
#include <stdio.h> // format print
/*
 *  read() is reading from FD 0 (std input), and buffer is the address of p (&p), reading at most the size of a pair_t.
 *  The read() command is just reading byte-by-byte the data that is the pair_t and filling up the memory region of p with those bytes.
 *  We can even use 3_write_pair.c as input of this program like this:
 *  ./3_write_pair | ./4_read_pair
 *  You should see the results as left: 10 right: 20
 *  The 3_write_apir program writes raw bytes of a pair to stdout which is piped to stdin of read_pair.
 *  4_read_pair then fills the buffer, that is the pair with those bytes and finally print them out to screen.
 */
typedef struct {
  int left;
  int right;
} pair_t;

int main(int argc, char * argv[]) {
    pair_t p;
    read(0, &p, sizeof(pair_t));
    printf("left: %d right: %d\n", p.left, p.right);
    return 0;
}

