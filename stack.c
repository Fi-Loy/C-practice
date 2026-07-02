#include <stdio.h>
#include "calc.h"
#define MAXVAL 100  // max depth of val stack

static int sp = 0;         // next free stack position
static double val[MAXVAL];  // value statck

//swapTop: swap the two top elements of the stack
void swapTop(void) {
    if (sp >= 2)
        val[sp] = (val[sp-1] + val[sp-2]) - (val[sp-1] = val[sp-2]);
    else 
        printf("Error: Stack has less than 2 values");
}

//clearStack: clear and reset stack
void clearStack(void) {
    sp = 0;
}

//peak: see the top value without removing it
double peek(void) {
    
    if (sp > 0)
        return val[sp-1];
    else {
        printf("Error: stack empty\n");
        return 0.0;
    }
}

//push: push f onto value stack
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("Error: stack full, can't push %g\n", f);
}

//pop: pop and return top value from stack
double pop(void) {
    if (sp > 0)
        return val[--sp] ;
    else {
        printf("Error: stack empty\n");
        return 0.0;
    }
}