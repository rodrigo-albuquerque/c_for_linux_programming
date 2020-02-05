#include <stdio.h>
#include <stdlib.h>
/*
 *  Suppose instead of reading/writing formatted data, we're interested in raw data.
 *  For that we use fread()/fwrite().
 *  size_t fred(void *ptr, size_t size, size_t nmemb, FILE *stream);
 *  size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
 *  The idea behind fread() and fwrite() is that it can be used to read/write arbitrarily stored data.
 *  *ptr references the memory to read from or write to (*void is because of no requirements on data type)
 *  size = how many bytes is e ach element to be read/written
 *  nmemb = number of such elements to read/write
 *  stream = file/stream to be read from/written to.
 *  Best way to see how this works is to look at basic example at how fread() and fwrite() are good for reading and writing arbitrary data.
 */

typedef struct {
  int left;
  int right;
} pair_t;

int main(int argc, char *argv[]) {
  pair_t pair;
  pair.left = 10;
  pair.right = 20;

  FILE * stream = fopen("pair.txt","w");
  fwrite(&pair, sizeof(pair_t), 1, stream);
  fclose(stream);
}
/*
 * Here, we've declared a pair on the stack, assigned its left and right value. And then we write the pair to the file pair.txt
 * Note that in this case we are writing one pair, so while the size of the pair is sizeof(pair_t) the nmemb is 1.
 * If we type ls -lh pair.txt we can see that it's 8B in size and will store the data that is integer 10 and 20.
 * We can use the command line tool xxd which prints each byte in hex: xxd -c 1 pair.txt
 * You should see the following output:
 * 0000000: 0a  .
 * 0000001: 00  .
 * 0000002: 00  .
 * 0000003: 00  .
 * 0000004: 14  .
 * 0000005: 00  .
 * 0000006: 00  .
 * 0000007: 00  .
 * The first column is the offset, so we have 8 bytes in the file.
 * The first 4 bytes are 0x0a000000 and the second are 0x14000000.
 * Computers store the least significant byte first, so these are the numbers 0x0a and 0x14, or 10 and 20 respectively.
 */
