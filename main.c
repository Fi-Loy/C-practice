//Note to next session:
//Working on Chapter 5.6: Pointer Arrays; Pointers to Pointers

#include <stdio.h>
#include <string.h>
#include "alloc.c"

#define MAXLINES 5000 //max # of lines to be sorted

char *lineptr[MAXLINES]; //pointers to text lines

int readlines(char* lineptr[], int nlines);
void writelines(char* lineptr[], int nlines);

void qsort(char* lineptr[], int left, int right);

//sort input lines
int main() {
    int nlines;

    if((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    }
    else {
        printf("Error: Input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000 //max length of any input line
int myGetline(char*, int);
char* alloc(int);

//readlines: read input lines
int readlines(char* lineptr[], int maxlines) {
    int len, nlines;
    char* p, line[MAXLEN];

    nlines = 0;
    while ((len = myGetline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0'; //delete newline
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

//writelines: write output lines
void writelines(char *lineptr[], int nlines){
    int i;

    for (i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
}

/* getline:  read a line into s, return length  */ 
int myGetline(char s[],int lim) 
{ 
    int c, i; 
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) 
        s[i] = c; 
    if (c == '\n') { 
        s[i] = c; 
        ++i; 
    } 
    s[i] = '\0'; 
    return i; 
} 

//qsort: sort v[left]...v[right] into increasing order
void qsort(char* v[], int left, int right) {
    int i, last; 
    void swap(char* v[], int i, int j);

    if (left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left; 
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0 )
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

//swap: interchange v[i] and v[j]
void swap(char* v[], int i, int j) {
    char* temp;

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