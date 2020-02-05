#include <stdio.h>
#include <stdlib.h>
/*
 *  We can convert argv[1] to int using sscanf() that reads any arbitrary strings rather than from standard input as is the case for scanf().
 *  sscanf() returns number of variables filled if successful, if no variable is successful it returns 0
 *  So in our program here we just added an if statement to check if it returns 0 and if so we throw an exception and exit.
 *  str − This is the C string that the function processes as its source to retrieve the data.
 *  sscanf(str, format, &var)
 *  str: the string we want to convert
 *  format: the format we want to convert to, i.e. %d for int, %s for string, etc.
 *  &var: optional parameter where when specified, we store the converted value into a variable (n in this case) but we need to add the &
 *  It can also be used like in a more complex way, lpease check 5_sscanf_example.c
 *  Nevertheless, it doesn't solve our problem where we have no parameters where it triggers a segmentation fault
 *  Reason is argv[2] references NULL so printf() tries to dereference a non-existent pointer.
 *  We solve that in 6_run_n_times.c
 */
int main(int argc, char *argv[]) {
  int i;
  int n;

  if ( sscanf(argv[1], "%d", &n) == 0 ) {
      fprintf(stderr, "ERROR: require a number\n");
      exit(1); // exits program
  }

  for (i=0; i<n; i++) {
    printf("%s\n", argv[2]);
  }
}

