#include <stdio.h>
#include <stdlib.h>

/*
 *  A common mistake when dealing with double pointers is poor deallocation.
 *  Let's extend previous example by modularising the process of creating the array of pair pointers.
 *  We can do that by adding a new pair into a function to simplify the code.
 *  The first function new_pairs() create the 10 empty pair_t pointers.
 *  The 2nd function, loop through the pointers to allocate pair_t values to next available pointer or return NULL if full.
 */

/*
 * We can't use a function like this to deallocate memory:
 * void delete_pairs(pair_t ** pairs) {
 *   free(pairs);
 *  Reason is because the index of pairs are pointers which may reference other allocated memory.
 *  We can't just free up the larger array without first deallocating memory referenced from within the array.
 *  If we do, then the address of that memory will be lost, thus leaking the memory.
 */

typedef struct {
  int left;
  int right;
} pair_t;

pair_t ** new_pairs() {
  pair_t ** pairs = (pair_t **) calloc(10, sizeof(pair_t *));
  return pairs;
}

pair_t * add_pair(pair_t ** pairs, int left, int right) {
  int i;
  for (i=0; i<10; i++) {
    if (pairs[i] == NULL) {
      pairs[i] = malloc(sizeof(pair_t)); // allocate
      pairs[i]->left = left; // do assignment
      pairs[i]->right = right;
      return pairs[i]; // return the new pair
    }
  }
  return NULL; //list is full, return NULL for error
}

void print_pairs(pair_t **pairs) { // void functions do not need return, so it's good for printing only
  for (int i=0; i<10; i++) {
    if (pairs[i] != NULL) {
      printf("pairs[%d]->left = %d\npairs[%d]->right = %d\n",i,pairs[i]->left, i,pairs[i]->right);
    }
  }
}

void delete_pairs(pair_t **pairs) {
  int i;
  for (i=0; i<10; i++) {
    if (pairs[i] != NULL) {
      free(pairs[i]);
    }
  }
  free(pairs); // free 'parent' array at the end
}

int main(int argc, char *argv[]) {
  pair_t ** pairs = new_pairs(); // create new array of 10 pair_t pointers by calling new_pairs() function where pointer "pairs" is the one pointing to such data structure
  add_pair(pairs, 2, 10); // assign new pair
  add_pair(pairs, 0, 3); // assign new pair
  add_pair(pairs, 5, 1);
  print_pairs(pairs);
  delete_pairs(pairs);
}
