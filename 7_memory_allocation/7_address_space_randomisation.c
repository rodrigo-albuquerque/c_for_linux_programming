#include <stdio.h>
#include <stdlib.h>

/*
 *  This program prints the address of statically declared variable a.
 *  While addresses are relatively high in addres space, significant bits are quite random.
 *  This is on purpose for security reasons.
 *  Stack contains important pointers to next bit of code that should be executed.
 *  This is how a program knows how to return to previous excecution prior to function call.
 *  In buffer overeflow attack, attacker overwrites return p ointer allowing code to be executed where attacker's choose.
 *  In order for attack to be successful, attacker must know exactly where in the program to set the return pointer.
 *  However, if addresses are randomised, it makes it a harder task and THIS is the reason why address space is randomised.
 */

int main(int argc, char *argv[]) {
  int a;
  printf("0x%p\n", &a); //print the address of a
}
// now try for i in `seq 1 1 10`; do ./7_address_space_randomisation; done
