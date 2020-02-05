#include <stdio.h>
#include <stdlib.h>

/*
 *  Just like we can format print to files, we can read/scan from a file using fscanf().
 *  It's just like scanf(), except it takes a file stream as file stream as first argument.
 *  For example, consider file.txt;
 *  Rodrigo Albuquerque 10 20 50 3.141592 yes
 *  Aline Pessoa 10 20 50 3.141592 yes
 *  One thing you should notice from the scanning loop is that we compare to EOF, which is special value for "End of File."
 *  The end of the file is encoded in such a way that you can compare against it.
 *  When scanning and you reach end of the file, EOF is returned, which can be detected and used to break the loop.
 *  Another item to note is that scanning with fscanf() is the same as that with scanf(), and is white space driven to separate different values to scan.
 *  Also, "%s" reads a word, as separated by white space, and does not read the whole line.
 */

int main(int argc, char * argv[]) {
  FILE * stream = fopen("file.txt", "r");
  char fname[1024],lname[1024],yesno[4];
  int a,b,c;
  float f;

  while ( fscanf(stream,
        "%s %s %d %d %d %f %s",
        fname, lname, &a, &b, &c, &f, yesno) != EOF) {
    printf("First Name: %s\n", fname);
    printf("Last Name: %s\n", lname);
    printf("        a %d\n", a);
    printf("        b %d\n", b);
    printf("        c %d\n", c);
    printf("        f %f\n", f);
    printf("        yesno: %s\n", yesno);
    printf("\n");
  }
  fclose(stream);
  return 0;
}
