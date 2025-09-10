//Note to next session:
//Working on Chapter 4.3 External Variables
/* Chapter 4.3 Example
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100  //max size of operator/operand
#define NUMBER '0' //signal that a number was found

int getop(char []);
void push(double);
double pop(void);

//reverse polish calculator
int main(){
    int type;
    double op2;
    char s[MAXOP];

    while((type = getop(s)) != EOF){
        switch(type) {
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
                    printf("Error: zero divisor\n");
            case '\n':
                printf("\t%.8g\n",pop());
                break;
            default:
                printf("Error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

#define MAXVAL 100 //max depth of val stack

int sp = 0;         //next free stack position
double val[MAXVAL]; //value stack

//push: push f onto value stack
void push(double f){
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("Error: stack full, cant push %g\n", f);
}

//pop: pop and return top value from stack
double pop(void){
    if (sp > 0)
        return val[--sp];
    else{
        printf("Error: stack empty\n");
        return 0.0;
    }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

//getop: get next character of numeric operand
int getop(char s[]){
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;  //not a number
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE];  //buffer for ungetch  
int bufp = 0;       //next free position in buf

int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else    
        buf[bufp++] = c;
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
//4.2 rewrite atof to handle sci notation