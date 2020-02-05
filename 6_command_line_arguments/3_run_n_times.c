#include <stdio.h>

/*
 *  We will often have to parse command line arguments when writing a program.
 *  This program prints a string a user specified 'n' times
 *  e.g. run_n_times 5 string
 *  atoi() is a function that converts a string to a number.
 *  However, atoi() doesn't detect errors when a string is not 'convertable'
 *  Try run_n_times notanumber string using below program and it will return 0
 *  How do we solve it? Move to run_n_times2.c
 */

int main(int argc, char *argv[]) {
  int i;
  int n = atoi(argv[1]); // does not detect errors when we add string that can't be converted to int

  for (i=0; i<n; i++) {
    printf("%s\n",argv[2]);
  }
}
