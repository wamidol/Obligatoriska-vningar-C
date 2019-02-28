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
    int *v = malloc(sizeof(*v));
    // Set value
    *v=3;
    // Pop element from stack
    s=stack_pop(s,v);
    // Free value
    free(v);

    // Pop one more element from stack
    s =stack_pop(s,v);
    // Free value
    free(v);

    int *stack_top(v);
    if(*stack_top!=1){
        //Write error message
        frprintf(stderr, "FAIL: Expected %d first in stuck got.\n",1, *stack_top);
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
void value_top_test() {
    // Create the stack
    stack *s=stack_empty(NULL);
    // Create one element
    int *v=malloc(sizeof(*v));
    // Set vallue.
    *v=4;
    // Push value on stack.
    s=stack_push(s,v);

    // Verify that value 4 is gonna be on top of stack.
    int *stack_top(v);
    if (*stack_top!=4) {
        // Write error message to stderr.
        fprintf(stderr, "FAIL: Expected %d first in stack, got %d stack.\n", 4, *stack_top);
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
        free(v);
    }
    // Finally, destroy the bare stack.
    stack_kills(s);
}
/*
 * Verifies that if we take the top element from a stack that is not empty and put it on the rest of the stack we get
 * the stack we began with.
 */

void top_element_stack() {

    // Create the stack.
    stack s*=stack_empty(NULL);

    for (int i=0; i<=99; i++) {
        s = stack_push(s, v);
    }
    for (int i=99; i<=0; i--) {

        if (stack_top(s) != i) {
            //Write error message
            frprintf(stderr, "FAIL: Expected %d first in stuck got.\n", 1, *stack_top);
            // Exit with error message
            exit(EXIT_FAILURE);
        }
        s = stack_pop(s);
    }

        // Verify that the element
        s=stack_push(stack_pop(s), stack_top(s))

        utan skriv anropet till stack_top(s) på en egen rad. gör en funktion som lägger in värden 1-9 9-1
    }
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

