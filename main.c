//Note to next session:
//Working on Chapter 4.5 Header Files

#include <stdio.h>
#include <stdlib.h> //for atof()
#include <math.h> //for fmod()
#include "calc.h"

#define MAXOP 100

//reverse Polish calculator
main() {
    /* stack testing code
    printf("Stack testing\n");
    printf("pushing 12\n");
    push(12);
    printf("pushing 4\n");
    push(4);
    printf("peeking top of stack: %f\n", peek());
    swapTop();
    printf("swapping top elements and peaking %f\n", peek());
    clearStack();
    printf("peaking empty stack: %f\n", peek());
    */
    
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF ) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("Error: zero divisor.\n");
                break;
            case '%':
                //TODO: COMPLETE
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("Error: domain error.");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("Error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

//2.9 Exercises : DONE
//2.10 Exercises : PARTIALLY DONE
//Exercises to return to
//3.3 else-if statements 
//sorting array algorithm : DONE
//binary search algorithm
//hexdump
//3.5 shell sort
//3.5 exercises
//3.5 reverse function
//4.1 rewrite strindex(s,t)
//4.2 rewrite atof to handle sci notation : DONE
//4.3 add modulus and negative numbers : DONE
//4.4 add peek, swapping, and stack clearing methods: DONE
//4.5 add access to library functions sin, exp, and pow
//4.6 add commands for having variables
//4.7 write a routine ungets(s)
//4.10 rewrite the calculator to use getline
//4.11 modify getop so that it doesnt use ungetch HINT: use an internal static variable
//4.12 write a recursive version of itoa
//4.13 write function that recursively reverses a string in place