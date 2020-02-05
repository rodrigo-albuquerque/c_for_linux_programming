#include <stdio.h>

/*
 *  Each functino is contained within a structure called stack frame.
 *  It contains all variable deliberations and a pointer to execution point of calling function, known as return pointer.
 *  Stack works with LIFO (Last In, First Out)
 *  Here's our example:
program executed     .------ top of stack
                                 v
                main()
push main         |      |     main()     |
                  |      '----------------'

              addonetwo()
                  |
push addonetwo    |      |   addonetwo()  |
                  |      |     main()     |
                  |      '----------------'

               getone()
                  |
                  |      |     getone()   |
push getone       |      |   addonetwo()  |
                  |      |     main()     |
                  |      '----------------'

               return 1
pop               |      |   addonetwo()  |
                  |      |     main()     |
                  |      '----------------'

               gettwo()
                  |
                  |      |     gettwo()   |
push gettwo       |      |   addonetwo()  |
                  |      |     main()     |
                  |      '----------------'

               return 2
pop               |      |   addonetwo()  |
                  |      |     main()     |
                  |      '----------------'

           return  1 + 2
pop               |      |     main()     |
                  |      '----------------'

             program exits
 *
 *  The act of pushing/popping functions onto stack affects memory allocation.
 *  By pushing a function onto stack, OS is actually allocating memory for function's local  variables.
 *  Once such function returns, both the function and its allocated memory is popped off the stack, deallocating it.
 *  This is why local declared variables are also called stacked variables.
 *  We can now understand why previous example fails by adding in PUSH/POP to it:
 *PUSH*            *POP*

            plus(1,2)         return &c            printf("%d\n",*p)

(main)         |  (main)         |  (main)            |  (main)
.---.----.     |  .---.----.     |  .---.----.        |  .---.----.
| p |  .-+-X   |  | p |  .-+-X   |  | p |  .-+---.    |  | p |  .-+---.
'---'----'     |  '---'----'     |  '---'----'   |    |  '---'----'   |
               | -------------   | ------------  |    |               |
               |  (plus)         |  (plus)       |    |               |
               |  .---.---.      |  .---.---.    |    |               |
               |  | a | 1 |      |  | a | 1 |    |    |               |
               |  |---|---|      |  |---|---|    |    |               |
               |  | b | 2 |      |  | b | 2 |    |    |               |
               |  |---|---|      |  |---|---|    |    |               |
               |  | c | 3 |      |  | c | 3 | <--'    |            X--'
               |  '---'---'      |  '-------'

             Pusing plus()           The return of plus()      When p is dereferenced
             onto the stack          pops it off the stack     in the print, p now
             allocates memory        unallocated all stack     references unallocated
             for c                   variables including c     memory
 */

int gettwo() {
  return 2;
}

int getone() {
  return 1;
}

int addonetwo() {
  int one = getone();
  int two = gettwo();
  return one+two;
}

int main(int argc, char * argv[]) {
  int a = addonetwo();
  printf("%d\n",a);
}
