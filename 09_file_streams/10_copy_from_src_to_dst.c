#include <stdio.h>
#include <stdlib.h>
/*
 * We read size of 1 byte with 1024 elements to fill up buffer
 * In while loop, we read a siez of 1 byte with 1024 elements, to fill up buffer.
 * Note that fread() returns the number of bytes read, so once the end of file is reached, 0 is returned so there's no data left to read.
 * Finally, we write data we read, but only as much as we read as stored in n.
 */
int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "ERROR: %s src dst\n",argv[0]);
    return 1;
  }

  FILE * src, * dst;

  src = fopen(argv[1], "r");
  dst = fopen(argv[2], "w");

  char data[1024]; // data buffer that can store 1024 bytes at a time
  int n;

  while ((n=fread(data,1,1024, src)) > 0) {
    fwrite(data, 1, n, dst);
  }
  fclose(src);
  fclose(dst);
  return 0;
}
