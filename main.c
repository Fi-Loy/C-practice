//Note to next session:
//Working on Chapter 5.11 Pointers to Functions

#include <stdio.h>
#include <string.h>
#include "hmHelpers.c"

#define MAXLINES 5000 //max num lines to be sorted
char *lineptr[MAXLINES]; //pointers to text lines

int readlines(char* lineptr[], int nlines);
void writelines(char* lineptr[], int nlines);

void myQsort(void* lineptr[], int left, int right, int (*comp)(void * , void *));
int numcmp(const char *,const char *);

//sort input lines
int main(int argc, char* argv[]) {
    
    int nlines; //number of input lines read
    int numeric = 0; // 1 if numeric sort

    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        myQsort((void**) lineptr, 0, nlines - 1, (int (*)(void*, void*))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines); 
        return 0;
    }
    else {
        printf("input too big to sort\n");
        return 1;
    }

}

//qsort: sort v[left]...v[right] into increasing order
void myQsort(void *v[], int left, int right, int (*comp) (void *, void *)) {
    int i, last;

    void swap(void *v[], int, int);

    if (left > right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) 
        if ((*comp) (v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    myQsort(v, left, last - 1, comp);
    myQsort(v, last + 1, right, comp);
}

#include <stdlib.h>

//numcmp: compare s1 and s2 numerically
int numcmp(const char* s1,const char* s2) {
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

//sawp:swap the position of two pointers
void swap(void *v[], int i, int j) {
    void* temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
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
//5.2 write getfloat, What type does getflow return as its function value?
//5.3 write a pointer version of the function strcat shown in Chapter 2 (DONE)
//5.4 write the function strend(s,t), which returns 1 is the string t occurs at the end of the string s, and 0 otherwise
//5.6 rewrite functions from earlier chapter with pointers instead of indexing
//5.10 rewrite the program expr, which can calculate a polish expression from the command line
//5.11 write the program tail, which prints the last n lines of input and can handle an optional argument "-n"
//5.14 to 5.17