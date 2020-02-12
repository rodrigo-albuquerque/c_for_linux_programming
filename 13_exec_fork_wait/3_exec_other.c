#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
/*
 *  Yes, I could've used argv[1] in the first argument
 */
int main(int argc, char * argv[]) {
  execvp((argv+1)[0], argv+1);
  perror("execvp failed");
}
