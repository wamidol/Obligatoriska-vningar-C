/*
 * An obligatory exercise to familiarize with the implementation of the datastructure Stack to learn how to test a
 * datastructure and to use dynamic allocation.
 *
 * Author: Mikolaj Wagner (c18mwj@cs.umu.se)
 *
 * Version information:
 *   2019-02-11: v1.0. first public version.
 *   2019-02-12: v1.1. all tests added (the next version need upgrade of some of the tests).
 *   2019-02-25: v2.0
 *   2019-02-28: v2.1 fixed all function to be correct.
 */


#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


/*
 * Verifies that a newly created empty stack is empty. Prints and error message to stderr and exits via exit() with an error
 * signal if the test fails.
 */
void empty_stack_test()
{
    // Create empty stack
    stack *s=stack_empty(NULL);

    // Verify the stack is empty
    if (!stack_is_empty(s)){
        // Write error message to stderr.
        fprintf(stderr, "FAIL: Expected empty stack, got stack with values.\n");
        // Exit with error message.
        exit(EXIT_FAILURE);

    }

    // The implementation passed the test. Clean up.

    // Deallocate the list structure.
    stack_kill(s);
}

/*
 * Verifies that a stack is not empty after it have been inserted with an element. Prints an error message to stderr and
 * exits via exit() with an error signal if the test fails.
 */
void one_element_test()
{
    // Create empty stack.
    stack *s=stack_empty(NULL);

    // Create one element
    int *v=malloc(sizeof(*v));
    *v=4;

    // Push value on stack.
    s=stack_push(s, v);

    // Verify that stack is NOT empty.
    if (stack_is_empty(s)) {
        // Write error message to stderr.
        fprintf(stderr, "FAIL: Expected NOT empty stack, got empty stack.\n");
        // Exit with error message.
        exit(EXIT_FAILURE);
    }

    // The implementation passed the test. Clean up.

    // Remove all elements from the stack.
    while (!stack_is_empty(s)) {
        // Get value from top of stack.
        int *v=stack_top(s);
        // Pop element from stack.
        s=stack_pop(s);
        // Free value
        free(v);

    }

    // Deallocate the stack structure.
    stack_kill(s);

}

/*
 * Verifies that if we insert a value on a stack and remove it instantly, we get the old stack back. Prints an error
 * message to stderr and exits via exit() with an error signal if the test fails.
 */
void value_remove_test()
{
    // Create empty stack
    stack *s=stack_empty(NULL);

    for (int i=1;i<=2; i++) {
        // Allocate of memory for one int.
        int *v = malloc(sizeof(*v));
        // Set value.
        *v = i;
        // Push value on stack.
        s = stack_push(s, v);
    }

    // Push one more value and allocate it
    int *k = malloc(sizeof(*k));
    // Set value
    *k=3;
    s=stack_push(s,k);
    // Pop element from stack
    s=stack_pop(s);

    // Pop one more element from stack
    s=stack_pop(s);
    // Free value
    free(k);

    // Verifie that the correctvalue is on top of stack.
    int *val = stack_top(s);
    //
    if(*val!=1){
        // Write error message
        fprintf(stderr, "FAIL: Expected %d first in stuck got %d.\n", 1, *val);
        // Exit with error message
        exit(EXIT_FAILURE);
    }

    // Empty the list.
    while (!stack_is_empty(s)) {
        // Get value from top of stack.
        int *v=stack_top(s);
        // Pop element from stack.
        s=stack_pop(s);
        // Free value
        free(v);
    }
    // Deallocate the stack structure.
    stack_kill(s);

}
/*
 * Verifies that if we insert a value to the stack it will result into that the value will get at the top of the stack.
 * Prints an error message to stderr and exits via exit() with an error signal if the test fails.
 */
void value_top_test()
{
    // Create the stack
    stack *s=stack_empty(NULL);
    // Create one element
    int *v=malloc(sizeof(*v));
    // Set vallue.
    *v=4;
    // Push value on stack.
    s=stack_push(s,v);

    // Verify that value 4 is gonna be on top of stack.
    int *val=stack_top(s);
    if (*val!=4) {
        // Write error message to stderr.
        fprintf(stderr, "FAIL: Expected %d first in stack, got %d.\n", 4, *val);
        // Exit with error message.
        exit(EXIT_FAILURE);
    }
    // Empty the list.
    while (!stack_is_empty(s)) {
        // Get value from top of stack.
        int *v=stack_top(s);
        // Pop element from stack.
        s=stack_pop(s);
        // Free value
        free(val);
        free(v);
    }
    // Finally, destroy the bare stack.
    stack_kill(s);
}
/*
 * Verifies that if we take the top element from a stack that is not empty and put it on the rest of the stack we get
 * the stack we began with.
 */

void top_element_stack()
{
    // Create the stack.
    stack *s=stack_empty(NULL);

    for (int i=0; i<=99; i++) {
        int *i=malloc(sizeof(*i));
        s=stack_push(s,i);
    }
    for (int i=99; i>=0; i--) {
        int *val=stack_top(s);
        if (*val!= i) {
            //Write error message
            fprintf(stderr, "FAIL: Expected %d in stuck got %d.\n", i, *val);
            // Exit with error message
            exit(EXIT_FAILURE);
        }
        s=stack_pop(s);
        // Free value
        free(val);
    }
    // Finally, destroy the stack
    stack_kill(s);
}



int main (void)
{
    fprintf(stderr,"Running TEST1: empty_stack_test(): ");
    empty_stack_test();
    fprintf(stderr,"OK.\n");
    fprintf(stderr,"Running TEST2: one_element_test(): ");
    one_element_test();
    fprintf(stderr,"OK.\n");
    fprintf(stderr,"Running TEST3: value_remove_test(): ");
    value_remove_test();
    fprintf(stderr,"OK.\n");
    fprintf(stderr,"Running TEST4: value_top_test(): ");
    value_top_test();
    fprintf(stderr,"OK.\n");
    fprintf(stderr,"Running TEST5: top_element_test(): ");
    top_element_stack();
    fprintf(stderr,"OK.\n");
    fprintf(stderr,"SUCCESS: Implementation passed all tests. Normal exit.\n");
    return 0;
}
